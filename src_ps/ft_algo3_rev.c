/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:45:07 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 14:46:01 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_algo3_rev2(t_stock **a, t_stock **b, int w, long end)
{
	long	first;
	long	mid;
	int		res;

	first = (*b)->data;
	mid = ((*b)->next)->data;
	res = 2;
	if (first > mid && mid < end && first > end)
	{
		use_sb(a, b, w);
		use_rb(a, b, w);
		return (res);
	}
	if (first < mid && mid < end && first < end)
	{
		use_rb(a, b, w);
		use_sb(a, b, w);
		return (res);
	}
	if (first < mid && mid > end && first > end)
	{
		res = 1;
		use_sb(a, b, w);
	}
	return (res);
}

int	ft_algo3_rev(t_stock **a, t_stock **b, int w)
{
	long	first;
	long	mid;
	long	end;
	int		res;

	res = 1;
	use_pb(a, b, w);
	use_pb(a, b, w);
	use_pb(a, b, w);
	first = (*b)->data;
	mid = ((*b)->next)->data;
	end = (((*b)->next)->next)->data;
	if (first > mid && mid < end && first < end)
	{
		use_rrb(a, b, w);
		return (res);
	}
	if (first < mid && mid > end && first < end)
	{
		use_rb(a, b, w);
		return (res);
	}
	res = ft_algo3_rev2(a, b, w, end);
	return (res);
}
