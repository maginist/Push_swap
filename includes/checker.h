/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:08:16 by maginist          #+#    #+#             */
/*   Updated: 2019/01/31 15:57:59 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_stock
{
	int				data;
	struct s_stock	*next;
}					t_stock;

int					arg_stock(int ac, char **av);
int					main(int ac, char **av);

#endif
