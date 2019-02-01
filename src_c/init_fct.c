/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:43:18 by maginist          #+#    #+#             */
/*   Updated: 2019/02/01 12:36:12 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	init_fct(void (*fct[11])(t_stock **a, t_stock **b))
{
	fct[0] = use_sa;
	fct[1] = use_sb;
	fct[2] = use_ss;
	fct[3] = use_pa;
	fct[4] = use_pb;
	fct[5] = use_ra;
	fct[6] = use_rb;
	fct[7] = use_rr;
	fct[8] = use_rra;
	fct[9] = use_rrb;
	fct[10] = use_rrr;
}
