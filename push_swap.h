/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/12 10:07:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void		sort_flush(t_stk **a, t_stk **b);
t_ttg		**init_known_strategies(t_ttg **k);
void		solve_known_strategies(t_ttg *k, t_stk *a, t_stk *b);

#endif
