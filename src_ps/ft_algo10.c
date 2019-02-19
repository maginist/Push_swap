/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:39:01 by maginist          #+#    #+#             */
/*   Updated: 2019/02/18 12:01:16 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algotest(t_stock **a, t_stock **b, int *minp, int *tmp)
{
	if (*minp <= (*tmp / 2) && *tmp > 0)
	{
		while (*minp != 0)
		{
			use_ra(a, b, 1);
			*minp -= 1;
		}
		use_pb(a, b, 1);
	}
	else
	{
		while (*minp < *tmp)
		{
			use_rra(a, b, 1);
			*minp += 1;
		}
		use_rra(a, b, 1);
		use_pb(a, b, 1);
	}
}

void	find_min(t_stock **a, int *pos, int *minp, int *tmp)
{
	t_stock	*cura;
	t_stock	*min;

	cura = (*a)->next;
	min = *a;
	while (cura)
	{
		if (min->data > cura->data)
		{
			min = cura;
			*minp = *pos;
		}
		cura = cura->next;
		*pos += 1;
	}
	*pos -= 1;
	*tmp = *pos;
}

int		size_list(t_stock **a)
{
	t_stock	*current;
	int		i;

	i = 0;
	current = *a;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

void	ft_algo10(t_stock **a, t_stock **b)
{
	int		pos;
	int		minp;
	int		tmp;

	minp = 0;
	pos = 1;
	tmp = 0;
	find_min(a, &pos, &minp, &tmp);
	algotest(a, b, &minp, &tmp);
	if (size_list(a) <= 3)
		ft_algo3(a);
	else
		ft_algo10(a, b);
	if (*b)
		use_pa(a, b, 1);
}
