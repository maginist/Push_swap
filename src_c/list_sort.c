/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:24:48 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 12:28:58 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int list_sort(t_stock **pile_a, t_stock **pile_b)
{
    t_stock *current;
    int tmp;

    tmp = 0;
    while ((*pile_a)->next)
    {
        if ((*pile_a)->data < ((*pile)->next)->data && (*pile_a)->next)
            *pile_a = (*pile_a)->next;
        else
            return (0);
    }
    if (!(*pile_b))
        return (1);
    else
        return (0);    
}