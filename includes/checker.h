/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:08:16 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 12:34:14 by maginist         ###   ########.fr       */
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

void				add_to_stock(t_stock **begin, int data);
int					arg_stock(int ac, char **av, t_stock *pile_a);
int					main(int ac, char **av);
int					inst_stock(t_stock *begin_i);
void				init_fct(void (*fct[11])(t_stock **a, t_stock **b));
void				(*fct[11])(t_stock **a, t_stock **b);
void				use_sa(t_stock **pile_a, t_stock **pile_b);
void				use_sb(t_stock **pile_a, t_stock **pile_b);
void				use_ss(t_stock **pile_a, t_stock **pile_b);
void				use_pa(t_stock **pile_a, t_stock **pile_b);
void				use_pb(t_stock **pile_a, t_stock **pile_b);
void				use_ra(t_stock **pile_a, t_stock **pile_b);
void				use_rb(t_stock **pile_a, t_stock **pile_b);
void				use_rr(t_stock **pile_a, t_stock **pile_b);
void				use_rra(t_stock **pile_a, t_stock **pile_b);
void				use_rrb(t_stock **pile_a, t_stock **pile_b);
void				use_rrr(t_stock **pile_a, t_stock **pile_b);

#endif
