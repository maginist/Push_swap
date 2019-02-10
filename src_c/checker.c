/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 16:06:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checker(int ac, char **av)
{
	t_stock	*begin_i;
	t_stock	*pile_a;
	t_stock	*pile_b;
	void	(*fct[11])(t_stock **a, t_stock **b, int w);

	init_fct(fct);
	pile_a = 0;
	pile_b = 0;
	begin_i = 0;
	if (!(arg_stock(ac, av, &pile_a)) || !(inst_stock(&begin_i)))
	{
		free_all_list(&pile_a, &begin_i);
		write(1, "Error\n", 6);
		return (0);
	}
	ft_display(&pile_a, &pile_b, ac, av);
	while (begin_i)
	{
		usleep(500000);
		fct[begin_i->data - 1](&pile_a, &pile_b, 0);
		begin_i = begin_i->next;
		ft_display(&pile_a, &pile_b, ac, av);
	}
	list_sort(&pile_a, &pile_b) ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	free_all_list(&pile_a, &begin_i);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		checker(ac, av);
	return (0);
}
