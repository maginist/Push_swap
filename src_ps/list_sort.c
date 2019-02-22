/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:25:57 by maginist          #+#    #+#             */
/*   Updated: 2019/02/22 15:03:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stock **a)
{
	t_stock *lol;

	lol = *a;
	while (lol)
	{
		printf("lol = %d\n", lol->data);
		lol = lol->next;
	}
}

int	pos_best(t_stock **a, t_stock *cur)
{
	int		pos;
	t_stock *beg;

	beg = *a;
	pos = 0;
	while (beg && beg->data != cur->data)
	{
		pos++;
		beg = beg->next;
	}
	return (pos);
}

int	list_sortb(t_stock **b)
{
	t_stock	*begin;

	begin = *b;
	while (begin && begin->next)
	{
		if (begin->data > (begin->next)->data)
			begin = begin->next;
		else
			return (0);
	}
	return (1);

}

int	list_sort(t_stock **pile_a, t_stock **pile_b)
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
