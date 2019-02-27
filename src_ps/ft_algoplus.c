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
	if (*a && posa < 0 && *b && posb < 0)
	{
		posb = size + posb;
		posa = sizea + posa;
		while (*a && posa > 0 && *b && posb > 0)
		{
			if ((*b)->data < best->data)
			{
				pb = *b;
				while (pb && pb->next)
					pb = pb->next;
				if (pb && pb->data > best->data)
					break ;
			}
			use_rrr(a, b, 1);
			posa--;
			posb--;
		}
	}
	if (*a && posa < 0)
	{
		posa = sizea + posa;
		while (*a && posa > 0)
		{
			use_rra(a, b, 1);
			posa--;
		}
	}
	posb = rot_cal(a, best, b, 5);
	while (*a && posa > 0 && *b && posb > 0)
	{
		use_rr(a, b, 1);
		posa--;
		posb--;
	}
	while (*a && posa > 0)
	{
		use_ra(a, b, 1);
		posa--;
	}
	while (*b && posb > 0)
	{
		use_rb(a, b, 1);
		posb--;
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
	make_it_sort(a, b);
	while (*b)
		use_pa(a, b, 1);
	return ;
}
