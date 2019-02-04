/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/04 13:36:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all_list(t_stock **pile_a, t_stock **begin_i)
{
	t_stock *current;
	t_stock *before;

	if (*pile_a)
	{
		before = *pile_a;
		current = (*pile_a)->next;
		free(before);
		*pile_a = 0;
		while (current)
		{
			before = current;
			current = before->next;
			free(before);
		}
	}
	if (*begin_i)
	{
		before = *begin_i;
		current = (*begin_i)->next;
		free(before);
		*begin_i = 0;
		while (current)
		{
			before = current;
			current = before->next;
			free(before);
		}
	}
}
