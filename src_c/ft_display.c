/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:32:46 by maginist          #+#    #+#             */
/*   Updated: 2019/02/08 16:15:29 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_display(t_stock **a, t_stock **b, int ac, char **av)
{
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'v')
	{
		printf("   | A || B |\n");
		while ((*a || *b) && ((*a)->next || (*b)->next))
		{
			printf("  | ");
			if (*a)
				printf("%d || ", (*a)->data);
			else
				printf("  || ");
			if (*b)
				printf("%d |\n", (*b)->data);
			else
				printf("  |\n");
			if (*a && (*a)->next)
				*a = (*a)->next;
			if (*b && (*b)->next)
				*b = (*b)->next;
		}
	}
}
