/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/02 12:01:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

int		treat_redundancies(t_ttg *strat);
t_ttg			**init_ps_strategy(t_ttg **k);
void			get_put_dump(t_stk **a, t_stk **b, char **o);
int				count_instructions_in_str(char *str);
char			*gen_push_swap(t_stk **a, t_stk **b);
void			give_it_to_stdout(t_ttg *s);
int				ps_try_bubble(t_stk **a, t_stk **b, char **o);
void			chain_push_swap(t_stk **a, t_stk **b, char **o);
int			is_(t_stk *s);
int			min_val(t_stk *ss);
int		count_gt(t_stk *h, int about);
int		count_le(t_stk *h, int about);
int				in_order_out_of_rot(t_stk *a);
int				in_reverse_out_of_rot(t_stk *a);
void			deb_stack_double_log(t_stk *a, t_stk *b);
t_stk		*stack_median(t_stk *s);
t_stk	*stack_short(t_stk *s);
void		gen_pivot_last(t_stk **a, int *pivot);
void		gen_pivot_median(t_stk **a, int *pivot);
void		gen_pivot_short(t_stk **a, int *pivot);
int			may_bubble(t_stk *a, int dir);
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
int		shortest_rotation_a_pivot(t_abo abo, int pivot);
void	shortest_rotation_a_receive(t_abo abo);
void	shortest_rotation_b_receive(t_abo abo);
int				position_top(t_stk *a, t_stk *h);
int				position_bot(t_stk *a, t_stk *h);
void	top_b(t_abo abo, t_stk *cell);
void	top_a(t_abo abo, t_stk *cell);
int				push_swap_sort(t_stk **a, t_stk **b, char **o);
t_stk	*stack_nclone(t_stk *s, int n);
void	exec(t_abo abo, char *mask);
int				ps_combo_rewind(t_stk **a, t_stk **b, char **o);
int				bubble(t_abo abo);
int		calc_top_a(t_abo abo, t_stk *cell);
int		calc_top_b(t_abo abo, t_stk *cell);
t_stk		*a_after_b(t_abo abo);
t_stk		*b_before_a(t_abo abo);
void	flush_b(t_abo abo);
void	flush_a(t_abo abo);
t_stk	**stack_ppclone(t_stk **s);
int		treat_str_redundancies(char **str);
char			*ft_trim(char *str);
void	treat_loc_redundancies(t_abo loc[TEST_NUM]);
void	count_loc_instructions(int c[TEST_NUM], t_abo loc[TEST_NUM]);
void	s_1_(t_abo loc);
void	s_2_(t_abo loc);
void	s_3_(t_abo loc);
void	s_4_(t_abo loc);
void	s_5_(t_abo loc);
void	s_6_(t_abo loc);
void	shortest_rotation_b_give(t_abo abo);
int				perfect_spot(t_abo abo);
char	*pivot_path(t_abo abo, int pivot, int c);
void	re_ouch(t_abo abo, char *ops);
void	gen_pivot_slice(t_stk *s, int *pivot, int slices);
char	*prev_command(char **h, char *limit);

#endif
