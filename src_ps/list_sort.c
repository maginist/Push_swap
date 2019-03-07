/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:25:57 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 14:46:42 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_it_sort(t_stock **a, t_stock **b)
{
	int		i;
	int		size;

	size = size_list(b);
	i = find_max(b);
	if (i >= size / 2)
		i = -i;
	if (i < 0)
	{
		i = size + i;
		while (i != 0)
		{
			use_rrb(a, b, 1);
			i--;
		}
	}
	else if (i > 0)
		while (i-- != 0)
			use_rb(a, b, 1);
	while (*b)
		use_pa(a, b, 1);
	return ;
}

int		list_sort(t_stock **pile_a, t_stock **pile_b)
{
	t_stock	*begin;

	begin = *pile_a;
	while (begin && (begin)->next)
	{
		if ((begin)->data < ((begin)->next)->data)
			begin = (begin)->next;
		else
			return (0);
	}
	if (!(*pile_b))
		return (1);
	else
		return (0);
}
