/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_dr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:47:34 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 15:48:54 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	use_rra(t_stock **pile_a, t_stock **pile_b)
{
	t_stock	*end;
	t_stock	*before;

	(void)pile_b;
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
	}
}

void	use_rrb(t_stock **pile_a, t_stock **pile_b)
{
	t_stock	*end;
	t_stock	*before;

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

void	use_rrr(t_stock **pile_a, t_stock **pile_b)
{
	use_rra(t_stock **pile_a, t_stock **pile_b);
	use_rrb(t_stock **pile_a, t_stock **pile_b);
}
