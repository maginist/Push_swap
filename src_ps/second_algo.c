/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:39:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/19 09:44:26 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size_post(t_stock *t, t_stock *pa)
{
	int		i;

	i = 0;
	while (pa->data != t->data)
	{
		pa = pa->next;
		i++;
	}
	return (i);
}

int	rotate_calcul(t_stock *pa, t_stock *c, t_stock *pb, int w)
{
	t_stock	*t;
	int		size;
	int		post;

	size = size_list(&pa);
	t = c;
	post = size_post(t, pa);
	if (post > size / 2)
	{
		while (t && t->next != pa->next)
		{
			post = 0;
			use_ra(&t, &pb, w);
			post++;
		}
		use_pb(&t, &pb, w);
		post++;
	}
	else
	{
		while (pa && t->next)
		{
			post = 0;
			use_rra(&pa, &pb, w);
			post++;
		}
		use_rra(&pa, &pb, w);
		use_pb(&pa, &pb, w);
		post++;
	}
	return (post);
}

void	second_algo(t_stock **a, t_stock **b, t_stock *pa, t_stock *pb)
{
	int		res;
	int		rb;
	t_stock	*current;
	t_stock	*best;

	current = *a;
	ft_algo3_rev(a, b, 1);
	best = current;
	while (current)
	{
		res = rotate_calcul(pa, current, pb, 0);
		rb = rotate_calcul(pa, current->next, pb, 0);
		if (rb < res)
		{
			best = current->next;
			current = current->next;
		}
		else
			current = current->next;
	}
	res = rotate_calcul(pa, best, pb, 1);
	return ;
}
