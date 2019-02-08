/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_p_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:35:26 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 15:16:12 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_pa(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*save;

	if (w == 1)
		write(1, "pa\n", 3);
	if (*pile_b)
	{
		save = 0;
		if ((*pile_b)->next)
			save = (*pile_b)->next;
		(*pile_b)->next = *pile_a;
		*pile_a = *pile_b;
		*pile_b = save;
	}
}

void	use_pb(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*save;

	if (w == 1)
		write(1, "pb\n", 3);
	if (*pile_a)
	{
		save = 0;
		if ((*pile_a)->next)
			save = (*pile_a)->next;
		(*pile_a)->next = *pile_b;
		*pile_b = *pile_a;
		*pile_a = save;
	}
}

void	use_ra(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*save;

	if (w == 1)
		write(1, "ra\n", 3);
	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		save = (*pile_a)->next;
		while (*pile_a && (*pile_a)->next)
			end = (*pile_a)->next;
		(*pile_a)->next = NULL;
		end->next = (*pile_a);
		*pile_a = save;
	}
}

void	use_rb(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*save;

	if (w == 1)
		write(1, "rb\n", 3);
	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		save = (*pile_b)->next;
		while ((*pile_b)->next)
			end = (*pile_b)->next;
		(*pile_b)->next = NULL;
		end->next = (*pile_b);
		*pile_b = save;
	}
}

void	use_rr(t_stock **pile_a, t_stock **pile_b, int w)
{
	use_ra(pile_a, pile_b, w);
	use_rb(pile_a, pile_b, w);
}
