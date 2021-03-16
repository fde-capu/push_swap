/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 20:42:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void			sort_flush(t_stk **a, t_stk **b);
t_ttg			**init_ps_strategy(t_ttg **k);
void			gen_split_low_high(t_stk **a, t_stk **b, int about, char **o);
void			get_put_dump(t_stk **a, t_stk **b, char **o);
int				count_instructions_in_str(char *str);
char			*gen_push_swap(t_stk **a, t_stk **b);
void			give_it_to_stdout(t_ttg *s);
int				ps_try_bubble(t_stk **a, t_stk **b, char **o);
void			chain_push_swap(t_stk **a, t_stk **b, char **o);
void			ouch(t_stk **a, t_stk **b, char **o, char *op);
int				is_in_order_rot(t_stk *s, char **o, int exec, char ab);
int			is_(t_stk *s);
int			min_val(t_stk *ss);


#endif
