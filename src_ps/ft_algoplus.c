/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:28:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 12:49:04 by maginist         ###   ########.fr       */
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
		if (posc >= size / 2)
			posc = -posc;
	return (posc);
}

void	rotate_end(t_stock **a, t_stock **b, int posb, t_stock *best)
{
	int		size;
	t_stock	*pb;

	size = size_list(b);
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

void	opti_rr(t_stock **a, t_stock **b, t_stock *best, int *posb)
{
	int		posa;

	posa = rot_cal(a, best, b, 4);
	*posb = rot_cal(a, best, b, 5);
	while (*a && posa > 0 && *b && *posb > 0)
	{
		use_rr(a, b, 1);
		posa--;
		(*posb)--;
	}
	while (*a && posa > 0)
	{
		use_ra(a, b, 1);
		posa--;
	}
	while (*b && *posb > 0)
	{
		use_rb(a, b, 1);
		(*posb)--;
	}
}

int		opti_rrr(t_stock **a, t_stock **b, t_stock *best, int *posb)
{
	int		sizea;
	int		size;
	int		posa;
	t_stock	*pb;

	posa = rot_cal(a, best, b, 4);
	sizea = size_list(a);
	size = size_list(b);
	*posb = size + *posb;
	posa = sizea + posa;
	while (*a && posa > 0 && *b && *posb > 0)
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
		(*posb)--;
	}
	return (posa);
}

void	real_rotate(t_stock **a, t_stock *best, t_stock **b)
{
	int		posb;
	int		size;
	int		posa;
	int		sizea;

	sizea = size_list(a);
	size = size_list(b);
	posa = rot_cal(a, best, b, 4);
	posb = rot_cal(a, best, b, 5);
	if (*a && posa < 0 && *b && posb < 0)
		posa = opti_rrr(a, b, best, &posb);
	if (*a && posa < 0)
	{
		posa = sizea + posa;
		while (*a && posa > 0)
		{
			use_rra(a, b, 1);
			posa--;
		}
	}
	opti_rr(a, b, best, &posb);
	if (*b && posb < 0)
		rotate_end(a, b, posb, best);
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
		cur = (*a)->next;
		rb  = rot_cal(a, best, b, 1) + rot_cal(a, best, b, 2);
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
