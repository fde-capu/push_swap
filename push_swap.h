/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 11:16:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int		treat_redundancies(t_ttg *strat);
void			sort_flush(t_stk **a, t_stk **b);
t_ttg			**init_ps_strategy(t_ttg **k);
void			get_put_dump(t_stk **a, t_stk **b, char **o);
int				count_instructions_in_str(char *str);
char			*gen_push_swap(t_stk **a, t_stk **b);
void			give_it_to_stdout(t_ttg *s);
int				ps_try_bubble(t_stk **a, t_stk **b, char **o);
void			chain_push_swap(t_stk **a, t_stk **b, char **o);
int			ouch(t_stk **a, t_stk **b, char **o, char *op);
int			is_(t_stk *s);
int			min_val(t_stk *ss);
int		count_gt(t_stk *h, int about);
int		count_le(t_stk *h, int about);
int				in_order_out_of_rot(t_stk *a);
int				in_reverse_out_of_rot(t_stk *a);
void			deb_stack_double_log(t_stk *a, t_stk *b);
int				ps_flush_ready(t_stk **a, t_stk **b, char **o);
t_stk		*stack_median(t_stk *s);
t_stk	*stack_short(t_stk *s);
void		gen_pivot_last(t_stk **a, int *pivot);
void		gen_pivot_median(t_stk **a, int *pivot);
void		gen_pivot_short(t_stk **a, int *pivot);
int			may_bubble(t_stk *a, int dir);
int	bubble_and_flush(t_stk **a, t_stk **b, char **o);
void			deb_pivot(int val);
t_stk	*filter_le(t_stk *s, int control);
int	check_nested(char *h, char *sub_code, char **end);
void	next_command(char **h);
char	**strip_sub_code(char *sub_code);
char	*gen_repetition(char *sub_code, int rep_count);
int	recursive_redundancy(char **str, char *sub_code);
int	substitute_redundancy(char **str, char *sub_code);
int	remove_str(char **str, char *rem);
int		treat_redundancies(t_ttg *strat);
void	solve_push_swap(t_ttg *k, t_stk *a);
int			main(int argc, char **argv);
int		ouch(t_stk **a, t_stk **b, char **o, char *op);
void			shortest_rotation_b_flush(t_stk **a, t_stk **b, char **o);
void			shortest_rotation_a_flush(t_stk **a, t_stk **b, char **o);
void			shortest_rotation_a_flush(t_stk **a, t_stk **b, char **o);
void			shortest_rotation_b_receive(t_stk **a, t_stk **b, char **o);
int			shortest_rotation_a_pivot(t_stk **a, t_stk **b, char **o, int pivot);
int				position_top(t_stk *a, t_stk *h);
int				position_bot(t_stk *a, t_stk *h);
void	put_cell_on_top_a(t_stk **a, t_stk **b, char **o, t_stk *cell);
void	put_cell_on_top_b(t_stk **a, t_stk **b, char **o, t_stk *cell);
t_stk			*this_is_before(t_stk *a, t_stk *b);
t_stk			*this_is_after(t_stk *a, t_stk *b);
void	shortest_rotation_a_receive(t_stk **a, t_stk **b, char **o);
int				push_swap_sort(t_stk **a, t_stk **b, char **o);
t_stk	*stack_nclone(t_stk *s, int n);
t_stk	*ab_destiny(t_abo abo, int dir);
t_stk	*ab_origin(t_abo abo, int dir);
void	ouch_abo(t_abo abo, int dir, char *mask);
int		pointer(int dir);
int			may_bubble_abo(t_abo abo, int dir);
int			may_bubble_abo_nx(t_abo abo, int dir);
void	gen_pivot_qs(t_abo abo, int dir, int len, int *pivot);
int				ps_combo_rewind(t_stk **a, t_stk **b, char **o);
void	gen_pivot_dir_short(t_abo abo, int dir, int len, int *pivot);
int				try_bubble_abo(t_abo abo, int dir);
int		pass_pivot(t_abo abo, int dir, int len, int pivot);
int		count_le_len(t_stk *h, int about, int len);
void	shortest_rotation_dir_receive(t_abo abo, int dir);
void	shortest_rotation_dir_pivot(t_abo abo, int dir, int pivot);

#endif
