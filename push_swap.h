/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:34:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

void	treat_redundancies(t_ttg *strat);
t_ttg	**init_ps_strategy(t_ttg **k);
void	get_put_dump(t_stk **a, t_stk **b, char **o);
int		count_instructions_in_str(char *str);
char	*gen_push_swap(t_stk **a, t_stk **b);
void	give_it_to_stdout(t_ttg *s);
int		ps_try_bubble(t_stk **a, t_stk **b, char **o);
void	chain_push_swap(t_stk **a, t_stk **b, char **o);
int		is_(t_stk *s);
int		min(int a, int b);
int		min_val(t_stk *ss);
int		count_gt(t_stk *h, int about);
int		count_le(t_stk *h, int about);
int		in_order_out_of_rot(t_stk *a);
int		in_reverse_out_of_rot(t_stk *a);
void	deb_stack_double_log(t_stk *a, t_stk *b);
t_stk	*stack_median(t_stk *s);
t_stk	*stack_short(t_stk *s);
void	gen_pivot_last(t_stk **a, int *pivot);
void	gen_pivot_median(t_stk **a, int *pivot);
void	gen_pivot_short(t_stk **a, int *pivot);
int		may_bubble(t_stk *a, int dir);
t_stk	*filter_le(t_stk *s, int control);
int		check_nested(char *h, char *sub_code, char **end);
void	next_command(char **h);
char	**strip_sub_code(char *sub_code);
char	*gen_repetition(char *sub_code, int rep_count);
int		recursive_redundancy(char **str, char *sub_code);
void	substitute_redundancy(char **str, char *sub_code);
int		remove_str(char **str, char *rem);
void	solve_push_swap(t_ttg *k, t_stk *a);
int		main(int argc, char **argv);
int		ouch(t_stk **a, t_stk **b, char **o, char *op);
int		shortest_rotation_a_pivot(t_abo abo, int pivot);
void	shortest_rotation_a_receive(t_abo abo);
void	shortest_rotation_b_receive(t_abo abo);
int		position_top(t_stk *a, t_stk *h);
int		position_bot(t_stk *a, t_stk *h);
void	top_b(t_abo abo, t_stk *cell);
void	top_a(t_abo abo, t_stk *cell);
int		push_swap_sort(t_stk **a, t_stk **b, char **o);
t_stk	*stack_nclone(t_stk *s, int n);
void	exec(t_abo abo, char *mask);
int		ps_combo_rewind(t_stk **a, t_stk **b, char **o);
int		bubble(t_abo abo);
int		calc_top_a(t_abo abo, t_stk *cell);
int		calc_top_b(t_abo abo, t_stk *cell);
t_stk	*a_after_b(t_abo abo);
t_stk	*b_before_a(t_abo abo);
void	flush_b(t_abo abo);
void	flush_a(t_abo abo);
t_stk	**stack_ppclone(t_stk **s);
int		treat_str_redundancies(char **str);
char	*ft_trim(char *str);
void	s_2_(t_abo loc);
void	s_3_(t_abo loc);
void	s_4_(t_abo loc);
void	s_5_(t_abo loc);
void	s_6_(t_abo loc);
void	shortest_rotation_b_give(t_abo abo);
int		spot_dn(t_abo abo);
int		spot_up(t_abo abo);
char	*pivot_path(t_abo abo, int pivot, int c);
void	re_ouch(t_abo abo, char *ops);
void	gen_pivot_slice(t_stk *s, int *pivot, int slices);
char	*prev_command(char **h, char *limit);
void	moderate_shortest_rotation_b_receive(t_abo abo);
int		any_in_range(t_stk *s, int min, int max);
void	gen_pivot_quad(t_stk *s, int pivot[4], int slices);
void	deb_quad_pivot(int pivot[4]);
void	gen_pivot_quad_sandwich(t_stk *s, int pivot[4], int slices);
int		shortest_rot_a_quad(t_abo abo, int pivot[4]);
int		is_in_range(int x, int min, int max);
void	cautious_top_b(t_abo abo, t_stk *cell);
int		val_after(t_stk *s, int med);
t_stk	*cell_val_after(t_stk *s, t_stk *h);
t_stk	*cell_val_before(t_stk *s, t_stk *h);
int		val_before(t_stk *s, int med);
void	short_b_receive_or_flush(t_abo abo);
int		spot(t_abo abo, char *op);
int		count_lasts_rb(t_abo abo);
int		rot_solve(int n, int r, int l);
void	gen_pivot_soft_quad_sand(t_stk *s, int pivot[4], int slices);
int		opportunistic_flush_b(t_abo abo);
int		shortest_a_btoa(t_abo abo);
int		count_natural_a_receive(t_abo abo);
int		count_reverse_a_receive(t_abo abo);
int		super_bubble(t_abo abo);
void	gen_pivot_quad_outside_in(t_stk *s, int pivot[4], int slices);
void	gen_pivot_quad_ref(t_stk *s, int pivot[4], int slices);
int		is_in_quad(int x, int pivot[4]);
int		full_rot_a_quad(t_abo abo, int pivot[4]);
void	deb_abo(t_abo abo);
int		shortest_b_btoa(t_abo abo);
int		master_rewind(t_abo abo);
int		count_lasts_ra(t_abo abo);
int		count_natural_b_give(t_abo abo);
int		count_reverse_b_give(t_abo abo);
int		any_in_quad_pivot(t_abo abo, int pivot[4]);
int		piv_lower(t_stk *cell, int pivot[4]);
int		piv_higher(t_stk *cell, int pivot[4]);
t_abo	make_abo(t_stk **a, t_stk **b, char **o);
void	rot_b_pb(t_abo abo);
int		soft_slice(t_abo abo);

#endif
