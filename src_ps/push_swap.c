/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:31:25 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 15:08:26 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(int ac, char **av)
{
	t_stock	*pile_a;
	t_stock	*pile_b;

	pile_a = 0;
	pile_b = 0;
	if (!(arg_stock(ac, av, &pile_a)))
	{
		free_all_list(&pile_a, &pile_b);
		write(1, "Error\n", 6);
		return ;
	}
	if (list_sort(&pile_a, &pile_b))
		return ;
	if (ac == 3)
		if ((pile_a)->data > ((pile_a)->next)->data)
			write(1, "sa\n", 3);
	if (ac == 4)
		ft_algo3(&pile_a);
	if (ac > 4 && ac <= 11)
		ft_algo10(&pile_a, &pile_b);
//	if (ac > 11)
//		ft_algoplus(&pile_a, &pile_b);
	free_all_list(&pile_a, &pile_b);
	return ;
}

int		main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}
