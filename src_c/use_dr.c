/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:47:34 by maginist          #+#    #+#             */
/*   Updated: 2019/02/11 15:53:08 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_rra(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*before;

	(void)pile_b;
	if (*pile_a && (*pile_a)->next)
	{
		if (w == 1)
			write(1, "rra\n", 4);
		before = (*pile_a);
		end = (*pile_a)->next;
		while (end->next)
		{
			before = before->next;
			end = end->next;
		}
		before->next = NULL;
		end->next = (*pile_a);
		*pile_a = end;
		return ;
	}
}

void	use_rrb(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*before;

	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
	{
		if (w == 1)
			write(1, "rrb\n", 4);
		before = (*pile_b);
		end = (*pile_b)->next;
		while (end->next)
		{
			before = before->next;
			end = end->next;
		}
		before->next = NULL;
		end->next = (*pile_b);
		*pile_b = end;
	}
}

void	use_rrr(t_stock **pile_a, t_stock **pile_b, int w)
{
	if (*pile_a && *pile_b)
	{
		if (w == 1)
			write(1, "rrr\n", 4);
		use_rra(pile_a, pile_b, 0);
		use_rrb(pile_a, pile_b, 0);
	}
}
