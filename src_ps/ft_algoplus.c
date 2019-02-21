/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:28:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/21 18:09:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	real_rotate(t_stock **a, t_stock *best, t_stock **b)
{

}

int		rot_calb(t_stock **a, t_stock *cur, t_stock **b)
{
	int		posc;
	int		size;

	size = size_list(b);
	posc = bien poser le cur;
	return (posc);
}

int		rot_cala(t_stock **a, t_stock *cur, t_stock **b)
{
	int		posc;
	int		size;

	size = size_list(a);
	posc = pos_best(a, cur);
	if (posc > size / 2)
		posc = -posc;
	return (posc);
}

void	ft_algoplus(t_stock **a, t_stock **b)
{
	int		res;
	int		rb;
	t_stock	*cur;
	t_stock	*best;

	ft_algo3_rev(a, b, 1);
	best = *a;
	while (*a)
	{
		cur = *a;
		while (cur && cur->next)
		{
			res = rot_cala(a, cur, b) + rot_calb(a, cur, b);
			rb = rot_cala(a, cur->next, b) + rot_calb(a, cur->next, b);
			if (res < rb)
				best = cur;
			cur = cur->next;
		}
		real_rotate(a, best, b);
		*a = (*a)->next;
	}
	while (*b)
		use_pa(a, b, 1);
	return ;
}
