/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:28:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/21 17:57:20 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rotate_calcul(t_stock **a, t_stock *cur, t_stock **b)
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
	t_stock	*current;
	t_stock	*best;

	ft_algo3_rev(a, b, 1);
	best = *a;
	while (*a)
	{
		current = *a;
		while (current && current->next)
		{
			res = rotate_calcul(a, current, b);
			rb = rotate_calcul(a, current->next, b);
			if (res < rb)
				best = current;
			current = current->next;
		}
		real_rotate(a, best, b, res);
		*a = (*a)->next;
	}
	while (*b)
		use_pa(a, b, 1);
	return ;
}
