/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:31:25 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 15:27:10 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algoplus(t_stock **a, t_stock **b)
{
	int		res;
	int		rb;
	t_stock	*cur;
	t_stock	*best;

	ft_algo3_rev(a, b, 1);
	while (*a)
	{
		best = *a;
		cur = (*a)->next;
		rb = rot_cal(a, best, b, 1) + rot_cal(a, best, b, 2);
		while (cur)
		{
			res = rot_cal(a, cur, b, 1) + rot_cal(a, cur, b, 2);
			if (res < rb)
			{
				best = cur;
				rb = res;
			}
			cur = cur->next;
		}
		real_rotate(a, best, b);
	}
	make_it_sort(a, b);
	return ;
}

void	algo(t_stock *pile_a, t_stock *pile_b, int ac)
{
	if (ac == 3)
		if ((pile_a)->data > ((pile_a)->next)->data)
		{
			write(1, "sa\n", 3);
			free_all_list(&pile_a);
			return ;
		}
	if (ac == 4)
		ft_algo3(&pile_a);
	else if (ac > 4 && ac <= 15)
		ft_algo10(&pile_a, &pile_b);
	else
		ft_algoplus(&pile_a, &pile_b);
	free_all_list(&pile_a);
	return ;
}

void	push_swap(int ac, char **av)
{
	t_stock	*pile_a;
	t_stock	*pile_b;

	pile_a = 0;
	pile_b = 0;
	if (!(arg_stock(ac, av, &pile_a)))
	{
		free_all_list(&pile_a);
		write(1, "Error\n", 6);
		return ;
	}
	if (list_sort(&pile_a, &pile_b))
	{
		free_all_list(&pile_a);
		return ;
	}
	algo(pile_a, pile_b, ac);
	return ;
}

int		main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}
