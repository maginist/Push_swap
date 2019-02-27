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
