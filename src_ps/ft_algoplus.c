/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:28:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/22 18:09:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_max(t_stock **b)
{
	//a garder
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
	{
		while (pb && pb->data < c->data)
		{
			inf++;
			pb = pb->next;
		}
		if(pb && pb->next && pb->next->data > c->data)
			while (pb && pb->next && pb->data > c->data)
			{
				inf++;
				pb = pb->next;
			} 
	}
	else if (pb && pb->data > c->data)
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

int		rot_cal(t_stock **a, t_stock *cur, t_stock **b, int w)
{
	int		posc;
	int		size;

	size = 0;
	posc = 0;
	if (w == 1 || w == 4)
	{
		size = size_list(a);
		posc = pos_best(a, cur);
	}
	else if (w == 2 || w == 5)
	{
		size = size_list(b);
		posc = pos_goodb(b, cur);
	}
	if (w > 3)
	{
		if (posc > size / 2)
			posc = -posc;
	}
	return (posc);
}

void	real_rotate(t_stock **a, t_stock *best, t_stock **b)
{
	int		posb;
	int		size;
	int		posa;
	int		sizea;
	t_stock	*pb;

	sizea = size_list(a);
	size = size_list(b);
	posa = rot_cal(a, best, b, 4);
	posb = rot_cal(a, best, b, 5);
	if (*a && posa < 0)
	{
		posa = sizea + posa;
		while (*a && posa > 0)
		{
			use_rra(a, b, 1);
			posa--;
		}
	}
	while (*a && posa > 0)
	{
		use_ra(a, b, 1);
		posa--;
	}
	if (*b && posb < 0)
	{
		posb = size + posb;
		while (*b && posb > 0)
		{
			if ((*b)->data < best->data)
			{
				pb = *b;
				while (pb && pb->next)
					pb = pb->next;
				if (pb && pb->data > best->data)
				{
					use_pb(a, b, 1);
					return ;
				}
			}
			use_rrb(a, b, 1);
			posb--;
		}
	}
	while (*b && posb > 0)
	{
		use_rb(a, b, 1);
		posb--;
	}
	use_pb(a, b, 1);
}

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
		cur = *a;
		while (cur)
		{
			res = rot_cal(a, cur, b, 1) + rot_cal(a, cur, b, 2);
			if (cur->next)
				rb = rot_cal(a, cur->next, b, 1) + rot_cal(a, cur->next, b, 2);
			if (res <= rb)
				best = cur;
			cur = cur->next;
		}
		real_rotate(a, best, b);
	}
	while (*b)
		use_pa(a, b, 1);
	return ;
}
