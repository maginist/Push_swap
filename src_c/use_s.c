/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_sa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:26:37 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 13:42:34 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	use_sa(t_stock **pile_a, t_stock **pile_b)
{
	int	tmp;

	(void)(*pile_b);
	if (*pile_a && (*pile_a)->next)
	{
		tmp = (*pile_a)->data;
		(*pile_a)->data = ((*pile_a)->next)->data;
		((*pile_a)->next)->data = tmp;
	}
}

void	use_sb(t_stock **pile_a, t_stock **pile_b)
{
	int tmp;
	t_stock *after;

	(void)(*pile_a);
	if (*pile_b && (*pile_b)->next)
	{
		after = (*pile_b)->next;
		tmp = (*pile_b)->data;
		(*pile_b)->data = after->data;
		after->data = tmp;
	}
}

void	use_ss(t_stock **pile_a, t_stock **pile_b)
{
	use_sa(pile_a, pile_b);
	use_sb(pile_a, pile_b);
}
