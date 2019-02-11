/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_p_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:35:26 by maginist          #+#    #+#             */
/*   Updated: 2019/02/11 15:51:37 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_pa(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*save;

	if (*pile_b)
	{
		if (w == 1)
			write(1, "pa\n", 3);
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

	if (*pile_a)
	{
		if (w == 1)
			write(1, "pb\n", 3);
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

	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		if (w == 1)
			write(1, "ra\n", 3);
		save = (*pile_a)->next;
		end = save;
		while (end && end->next)
			end = end->next;
		(*pile_a)->next = NULL;
		end->next = (*pile_a);
		*pile_a = save;
	}
}

void	use_rb(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*save;

	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		if (w == 1)
			write(1, "rb\n", 3);
		save = (*pile_b)->next;
		end = save;
		while (end && end->next)
			end = end->next;
		(*pile_b)->next = NULL;
		end->next = (*pile_b);
		*pile_b = save;
	}
}

void	use_rr(t_stock **pile_a, t_stock **pile_b, int w)
{
	if (*pile_a && *pile_b)
	{
		if (w == 1)
			write(1, "rr\n", 3);
		use_ra(pile_a, pile_b, 0);
		use_rb(pile_a, pile_b, 0);
	}
}
