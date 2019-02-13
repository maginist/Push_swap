/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:22:24 by maginist          #+#    #+#             */
/*   Updated: 2019/02/13 18:45:54 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all_list(t_stock **pile_a)
{
	t_stock	*current;
	t_stock	*before;

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
}
