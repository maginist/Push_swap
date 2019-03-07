/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:57:26 by maginist          #+#    #+#             */
/*   Updated: 2019/03/05 14:23:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		inst_valid(char *str)
{
	if (str && ft_strcmp(str, "sa") == 0)
		return (1);
	else if (str && ft_strcmp(str, "sb") == 0)
		return (2);
	else if (str && ft_strcmp(str, "ss") == 0)
		return (3);
	else if (str && ft_strcmp(str, "pa") == 0)
		return (4);
	else if (str && ft_strcmp(str, "pb") == 0)
		return (5);
	else if (str && ft_strcmp(str, "ra") == 0)
		return (6);
	else if (str && ft_strcmp(str, "rb") == 0)
		return (7);
	else if (str && ft_strcmp(str, "rr") == 0)
		return (8);
	else if (str && ft_strcmp(str, "rra") == 0)
		return (9);
	else if (str && ft_strcmp(str, "rrb") == 0)
		return (10);
	else if (str && ft_strcmp(str, "rrr") == 0)
		return (11);
	return (0);
}

int		inst_stock(t_stock **begin_i)
{
	int			ok;
	char		*str;

	str = NULL;
	while ((get_next_line_mod(0, &str) > 0))
	{
		if (!(ok = inst_valid(str)))
		{
			if (str)
				ft_strdel(&str);
			return (0);
		}
		else
			add_to_stock(begin_i, ok);
		if (str)
			ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	return (1);
}
