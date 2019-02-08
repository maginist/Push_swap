/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:39:01 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 15:27:11 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_algo10(t_stock **a, t_stock **b)
{
	t_stock	*cura;
	t_stock	*min;
	int		pos;
	int		minp;
	int tmp;

	cura = *a;
	min = cura;
	minp = 0;
	pos = 0;
	while (cura && cura->next)
	{
		if (min->data > (cura->next)->data)
		{
			min = cura;
			minp = pos;
		}
			cura = cura->next;
			pos++;
	}
	pos--;
	tmp = pos;
	if (minp < (tmp / 2) && pos > 0)
	{
		while (minp != 0)
		{
			use_ra(a, b, 1);
			minp--;
		}
		use_pb(a, b, 1);
	}
	else
	{
		while (minp != pos && pos > 0)
		{
			sleep(1);
			use_rra(a, b, 1);
			minp++;
		}
		use_rra(a, b, 1);
		use_pb(a, b, 1);
	}
	if ((*a))
		ft_algo10(a, b);
	while (*b)
		use_pa(a, b, 1);
}
