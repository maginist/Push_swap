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

static int	sizet(t_stock *a)
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
		ret = 1;
	while (i != 0)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

void	ft_display(t_stock **a, t_stock **b, int ac, char **av)
{
	t_stock	*cura;
	t_stock	*curb;

	cura = *a;
	curb = *b;
	system("clear");
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'v')
	{
		write(1, "           _______  _______ \n", 29);
		write(1, "          |   A   ||   B   |\n", 29);
		write(1, "          |-------||-------|\n", 29);
		while ((cura || cura->next != NULL) || (curb || curb->next != NULL))
		{
			write(1, "          |", 11);
			if (cura && sizet(cura) == 1)
			{
				write(1, "   ", 3);
				ft_putnbr(cura->data);
				write(1, "   ||", 5);
			}
			else if (cura && sizet(cura) == 2)
			{
				write(1, "  ", 2);
                                ft_putnbr(cura->data);
                                write(1, "   ||", 5);
			}
			else if (cura && sizet(cura) == 3)
      			{
                                write(1, "  ", 2);
                               	ft_putnbr(cura->data);
                                write(1, "  ||", 4);
                        }
			else if (cura && sizet(cura) == 4)
                        {
                                write(1, " ", 1);
                                ft_putnbr(cura->data);
                                write(1, "  ||", 4);
                        }
			else if (sizet(cura) > 4 && sizet(cura) < 1)
				write(1, "       ||", 9);
			if (curb && sizet(curb) == 1)
                        {
                                write(1, "   ", 3);
                                ft_putnbr(cura->data);
                                write(1, "   |\n", 5);
                        }
			else if (curb && sizet(curb) == 2)
                        {
                                write(1, "  ", 2);
                                ft_putnbr(cura->data);
                                write(1, "   |\n", 5);
                        }
			else if (curb && sizet(curb) == 3)
                        {
                                write(1, "  ", 2);
                                ft_putnbr(cura->data);
                                write(1, "  |\n", 4);
                        }
			else if (curb && sizet(curb) == 4)
                        {
                                write(1, " ", 1);
                                ft_putnbr(cura->data);
                                write(1, "  |\n", 4);
                        }
			else
				write(1, "       |\n", 9);
			if (cura && cura->next)
				cura = cura->next;
			if (curb && curb->next)
				curb = curb->next;
			if ((cura && (cura->next)->data == 0) && (curb && (curb->next)->data == 0))
				break ;
		}
		write(1, "          |_______||_______|\n", 29);
	}

	else
		return ;
}
