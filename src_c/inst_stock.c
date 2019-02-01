/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:57:26 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 11:40:09 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	add_to_stock(t_stock **begin, int data)
{
	t_stock *new;
	t_stock *current;

	if (!(new = (t_stock*)malloc(sizeof(t_stock) * 1)))
		return ;
	new->data = data;
	new->next = 0;
	if (!(*begin))
		*begin = new;
	else
	{
		current = *begin;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

int	inst_valid(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (2);
	else if (ft_strcmp(str, "ss") == 0)
		return (3);
	else if (ft_strcmp(str, "pa") == 0)
		return (4);
	else if (ft_strcmp(str, "pb") == 0)
		return (5);
	else if (ft_strcmp(str, "ra") == 0)
		return (6);
	else if (ft_strcmp(str, "rb") == 0)
		return (7);
	else if (ft_strcmp(str, "rr") == 0)
		return (8);
	else if (ft_strcmp(str, "rra") == 0)
		return (9);
	else if (ft_strcmp(str, "rrb") == 0)
		return (10);
	else if (ft_strcmp(str, "rrr") == 0)
		return (11);
	return (0);
}

int	inst_stock(t_stock *begin_i)
{
	int ok;
	int ret;
	char *str;

	while ((ret = get_next_line_mod(0, &str)))
	{
		if (!(ok = inst_valid(str)))
			return (0);
		else
			add_to_stock(&begin_i, ok);
	}
	return (0);
}
