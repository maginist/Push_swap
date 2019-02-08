/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:47:34 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 15:16:53 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_rra(t_stock **pile_a, t_stock **pile_b, int w)
{
	t_stock	*end;
	t_stock	*before;

	(void)pile_b;
	if (w == 1)
		write(1, "rra\n", 4);
	if (*pile_a && (*pile_a)->next)
	{
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

	if (w == 1)
		write(1, "rrb\n", 4);
	(void)pile_a;
	if (*pile_b && (*pile_b)->next)
	{
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
	use_rra(pile_a, pile_b, w);
	use_rrb(pile_a, pile_b, w);
}
