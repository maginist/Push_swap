/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 12:28:58 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_swap(int ac, char **av)
{
    t_stock	*begin_i;
	t_stock	*pile_a;
	t_stock	*pile_b;
	void	(*fct[11])(t_stock **a, t_stock **b);

	init_fct(fct);
	pile_a = 0;
	pile_b = 0;
	begin_i = 0;
	if (!(arg_stock(ac, av, pile_a) || inst_stock(begin_i)))
	{
		free_all_list(&pile_a, &begin_i);
		write(1, "Error\n", 6);
		return (0);
    }
	ft_algodemerde(&pile_a, &pile_b, &begin_i, fct);
	free_all_list(&pile_a, &begin_i);
}

int     main(int ac, char **av)
{
    if (ac > 1)
        push_swap(ac, av);
    return (0);
}