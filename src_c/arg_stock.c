/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:33:08 by maginist          #+#    #+#             */
/*   Updated: 2019/01/31 15:56:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	nbdouble(int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	j = 2;
	while (i < ac)
	{
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arg_stock(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		return (2);
	while (i < ac)
	{
		j = ft_strlen(av[i]);
		if (ft_atoi(av[i]) == 0 && av[i][j - 1] != '0')
			return (0);
		while (--j > 0)
			if (!(ft_isdigit(av[i][j])))
				return (0);
		if ((ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647)
				|| ft_strlen(av[i]) > 11)
			return (0);
		i++;
	}
	return ((nbdouble(ac, av)) ? 0 : 1);
}
