/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_stock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:33:08 by maginist          #+#    #+#             */
/*   Updated: 2019/02/13 18:22:47 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_to_stock(t_stock **begin, int data)
{
	t_stock	*new;
	t_stock	*current;

	current = NULL;
	new = NULL;
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

int		nbdouble(int ac, char **av, t_stock **pile_a)
{
	int	i;
	int j;

	i = 1;
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'v')
		i = 2;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		add_to_stock(pile_a, ft_atoi(av[i]));
		i++;
	}
	return (0);
}

int		arg_stock(int ac, char **av, t_stock **pile_a)
{
	int	i;
	int	j;

	i = 1;
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'v')
		i = 2;
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
	return ((nbdouble(ac, av, pile_a)) ? 0 : 1);
}
