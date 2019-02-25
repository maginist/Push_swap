/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:32:46 by maginist          #+#    #+#             */
/*   Updated: 2019/02/13 16:37:39 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sizet(t_stock *a)
{
	int	i;
	int	ret;

	i = a->data;
	ret = 0;
	if (i >= 0 && i <= 9)
		return (1);
	if (i <= -1 && i >= -9)
		return (2);
	if (i < 0)
		ret++;
	while (i != 0)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

void	ft_display_nbr(t_stock *a)
{
	int		space;
	int		nbra;
	int		spaceb;

	nbra = sizet(a);
	spaceb = 6;
	space = 6;
	while ((nbra + space + spaceb) != 13 && space > 0 && spaceb > 0)
	{
		if ((nbra % 2) != 1 && (nbra + space + spaceb) < 13)
		{
			spaceb++;
			break ;
		}
		spaceb--;
		space--;
	}
	while (space-- != 0)
		write(1, " ", 1);
	(a->data) ? ft_putnbr(a->data) : space++;
	if (a->data == 0)
		write(1, "0", 1);
	while (spaceb-- != 0)
		write(1, " ", 1);
}

void	print_tab(void)
{
	//system("clear");
	write(1, "           _____________  _____________ \n", 41);
	write(1, "          |      A      ||      B      |\n", 41);
	write(1, "          |-------------||-------------|\n", 41);
}

void	ft_display(t_stock **a, t_stock **b, int ac, char **av)
{
	t_stock	*cura;
	t_stock	*curb;

	cura = *a;
	curb = *b;
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'v')
	{

		usleep(1000000);//600000
		print_tab();
		while (cura || curb)
		{
			write(1, "          |", 11);
			(cura) ? ft_display_nbr(cura) : write(1, "             ", 13);
			write(1, "||", 2);
			(curb) ? ft_display_nbr(curb) : write(1, "             ", 13);
			write(1, "|\n", 2);
			if (cura)
				cura = cura->next;
			if (curb)
				curb = curb->next;
		}
		write(1, "          |_____________||_____________|\n", 41);
	}
	return ;
}
