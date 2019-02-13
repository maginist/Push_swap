/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:51:13 by maginist          #+#    #+#             */
/*   Updated: 2019/02/13 17:23:03 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo3_2(int first, int mid, int end)
{
	if (first > mid && mid > end && first > end)
	{
		write(1, "sa\nrra\n", 7);
		return ;
	}
	if (first < mid && mid > end && end < first)
		write(1, "rra\n", 4);
}

void	ft_algo3(t_stock **a)
{
	long	first;
	long	mid;
	long	end;

	first = (*a)->data;
	mid = ((*a)->next)->data;
	end = (((*a)->next)->next)->data;
	if (first > mid && mid < end && end > first)
	{
		write(1, "sa\n", 3);
		return ;
	}
	if (first < mid && mid > end && first < end)
	{
		write(1, "rra\nsa\n", 7);
		return ;
	}
	if (first > mid && mid < end && first > end)
	{
		write(1, "ra\n", 3);
		return ;
	}
	ft_algo3_2(first, mid, end);
	return ;
}
