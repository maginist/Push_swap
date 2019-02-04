/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/04 13:11:31 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int list_sort(t_stock **pile_a, t_stock **pile_b)
{
    while (*pile_a && (*pile_a)->next)
    {
		printf("data =%d, data-next = %d\n", (*pile_a)->data, ((*pile_a)->next)->data);
        if ((*pile_a)->data < ((*pile_a)->next)->data)
            *pile_a = (*pile_a)->next;
        else
            return (0);
    }
    if (!(*pile_b))
        return (1);
    else
        return (0);
}
