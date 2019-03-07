/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_killer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 11:03:41 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 14:48:42 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		pos_best(t_stock **a, t_stock *cur)
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

int		find_max(t_stock **b)
{
	t_stock *beg;
	t_stock	*max;
	int		posm;
	int		pos;

	pos = 0;
	posm = 0;
	max = *b;
	beg = (*b)->next;
	while (beg)
	{
		pos++;
		if (max->data < beg->data)
		{
			posm = pos;
			max = beg;
		}
		beg = beg->next;
	}
	return (posm);
}

int		pos_goodb2(t_stock *pb, t_stock *c, int inf, t_stock **b)
{
	while (pb && pb->data < c->data)
	{
		inf++;
		pb = pb->next;
	}
	if (pb && pb->data > c->data)
	{
		while (pb && pb->data > c->data)
		{
			inf++;
			pb = pb->next;
		}
	}
	if (!(pb))
		inf = find_max(b);
	return (inf);
}

int		pos_goodb(t_stock **b, t_stock *c)
{
	int		inf;
	t_stock	*pb;
	t_stock *end;

	end = *b;
	pb = *b;
	while (end->next)
		end = end->next;
	if (end->data > c->data && pb->data < c->data)
		return (0);
	inf = 0;
	if (pb && pb->data < c->data)
		inf = pos_goodb2(pb, c, inf, b);
	else if (pb && pb->data > c->data)
		while (pb && pb->data > c->data)
		{
			inf++;
			pb = pb->next;
		}
	if (!(pb))
		inf = find_max(b);
	return (inf);
}
