/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:11:43 by maginist          #+#    #+#             */
/*   Updated: 2018/11/14 10:35:07 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		xmax;
	int		xmin;
	char	tamp;

	xmin = 0;
	xmax = ft_strlen(str);
	while (xmin < xmax)
	{
		tamp = str[xmax - 1];
		str[xmax - 1] = str[xmin];
		str[xmin] = tamp;
		xmin++;
		xmax--;
	}
	return (str);
}
