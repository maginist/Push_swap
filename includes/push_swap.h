/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:08:16 by maginist          #+#    #+#             */
/*   Updated: 2019/02/28 14:42:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_stock
{
	int				data;
	struct s_stock	*next;
}					t_stock;

int					find_max(t_stock **b);
void				make_it_sort(t_stock **a, t_stock **b);
int					pos_goodb(t_stock **b, t_stock *c);
int					pos_best(t_stock **a, t_stock *cur);
int					list_sortb(t_stock **b);
int					size_list(t_stock **a);
int					ft_algo3_rev(t_stock **a, t_stock **b, int w);
void				ft_display(t_stock **a, t_stock **b, int ac, char **av);
void				add_to_stock(t_stock **begin, int data);
int					arg_stock(int ac, char **av, t_stock **pile_a);
int					checker(int ac, char **av);
int					inst_stock(t_stock **begin_i);
void				init_fct(void (*fct[11])(t_stock **a, t_stock **b, int w));
void				use_sa(t_stock **pile_a, t_stock **pile_b, int w);
void				use_sb(t_stock **pile_a, t_stock **pile_b, int w);
void				use_ss(t_stock **pile_a, t_stock **pile_b, int w);
void				use_pa(t_stock **pile_a, t_stock **pile_b, int w);
void				use_pb(t_stock **pile_a, t_stock **pile_b, int w);
void				use_ra(t_stock **pile_a, t_stock **pile_b, int w);
void				use_rb(t_stock **pile_a, t_stock **pile_b, int w);
void				use_rr(t_stock **pile_a, t_stock **pile_b, int w);
void				use_rra(t_stock **pile_a, t_stock **pile_b, int w);
void				use_rrb(t_stock **pile_a, t_stock **pile_b, int w);
void				use_rrr(t_stock **pile_a, t_stock **pile_b, int w);
int					list_sort(t_stock **pile_a, t_stock **pile_b);
void				push_swap(int ac, char **av);
void				free_all_list(t_stock **pile_a);
void				ft_algo3(t_stock **a);
void				ft_algo10(t_stock **a, t_stock **b);
void				real_rotate(t_stock **a, t_stock *best, t_stock **b);
int					rot_cal(t_stock **a, t_stock *cur, t_stock **b, int w);

#endif
