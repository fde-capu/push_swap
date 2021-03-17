/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/17 18:00:30 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void			sort_flush(t_stk **a, t_stk **b);
t_ttg			**init_ps_strategy(t_ttg **k);
void			get_put_dump(t_stk **a, t_stk **b, char **o);
int				count_instructions_in_str(char *str);
char			*gen_push_swap(t_stk **a, t_stk **b);
void			give_it_to_stdout(t_ttg *s);
int				ps_try_bubble(t_stk **a, t_stk **b, char **o, t_stk **h);
void			chain_push_swap(t_stk **a, t_stk **b, char **o);
void			ouch(t_stk **a, t_stk **b, char **o, char *op);
int			is_(t_stk *s);
int			min_val(t_stk *ss);
int		count_gt(t_stk *h, int about);
int		count_le(t_stk *h, int about);
t_stk		*min_cell(t_stk *ss);
t_stk		*max_cell(t_stk *ss);
int			in_order(t_stk *s);
int			in_reverse(t_stk *s);
void	re_ouch(t_stk **a, t_stk **b, char **o, char *ops);
int				in_order_out_of_rot(t_stk *a);
int				in_reverse_out_of_rot(t_stk *a);
void			deb_stack_double_log(t_stk *a, t_stk *b);
int				ps_flush_ready(t_stk **a, t_stk **b, char **o);
t_stk		*stack_median(t_stk *s);


#endif
