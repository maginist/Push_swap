/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_sa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:26:37 by maginist          #+#    #+#             */
/*   Updated: 2019/02/11 15:54:24 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_sa(t_stock **pile_a, t_stock **pile_b, int w)
{
	int		tmp;

	(void)(*pile_b);
	if (*pile_a && (*pile_a)->next)
	{
		if (w == 1)
			write(1, "sa\n", 3);
		tmp = (*pile_a)->data;
		(*pile_a)->data = ((*pile_a)->next)->data;
		((*pile_a)->next)->data = tmp;
	}
}

void	use_sb(t_stock **pile_a, t_stock **pile_b, int w)
{
	int		tmp;
	t_stock	*after;

	(void)(*pile_a);
	if (*pile_b && (*pile_b)->next)
	{
		if (w == 1)
			write(1, "sb\n", 3);
		after = (*pile_b)->next;
		tmp = (*pile_b)->data;
		(*pile_b)->data = after->data;
		after->data = tmp;
	}
}

void	use_ss(t_stock **pile_a, t_stock **pile_b, int w)
{
	if (*pile_a && *pile_b)
	{
		if (w == 1)
			write(1, "ss\n", 3);
		use_sa(pile_a, pile_b, w);
		use_sb(pile_a, pile_b, w);
	}
}
