/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoplus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:28:28 by maginist          #+#    #+#             */
/*   Updated: 2019/02/13 17:15:17 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	select_algo(t_stock **a, t_stock **b, int pivot)
{
	t_stock *pa;
	t_stock	*piv;
	int	res;

	res = 0;
	pa = *a;
	while (pa && (pa->next)->data != pivot)
		pa = pa->next;
	piv = pa->next;
	res = first_algo(piv, a, b, 0);
	if (res < second_algo(piv, a, b, 0))
		res = first_algo(piv, a, b, 1);
	else
		res = second_algo(piv, a, b, 1);
	return ;
}


int	find_median(int *tab, int j)
{
	int	i;

	i = (j / 2);
	return (tab[i]);
}

int	srchpiv(t_stock **a)
{
	int		*tab;
	unsigned int	i;
	t_stock		*current;
	int		j;

	j = 0;
	current = *a;
	i = 0;
	while (current)
	{
		i++;
		current = current->next;
	}
	if (!(tab = (int*)malloc(sizeof(int) * i)))
		return (0);
	current = *a;
	while (current)
	{
		tab[j++] = current->data;
		current = current->next;
	}
	sort_int_tab(tab, i);
	i = find_median(tab, j);
	free(tab);
	return (i);
}

void	ft_algoplus(t_stock **a, t_stock **b)
{
	int	pivot;

	pivot =	srchpiv(a);
	printf("pivot = %d\n", pivot);
	select_algo(a, b, pivot);
	return ;
}
