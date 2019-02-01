/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 12:28:58 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all_list(t_stock **pile_a, t_stock **begin_i)
{
	t_stock *current;

	if (*pile_a)
	{
		current = *pile_a;
		while (current->next)
			free(current);
	}
	if (*begin_i)
	{
		current = *begin_i;
		while (current->next)
			free(current);
	}
}
