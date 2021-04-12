/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:17:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/12 14:19:29 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "defs.h"
# include "get_next_line_bonus.h"


#include <stdio.h>

int	identxl(char *a, char *b);
int	ident(char *a, char *b);
long long	ft_atoi(const char *str);
long long	ft_atol(const char *str);
int			ft_isdigit(int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrimx(char *s1, char *set);
char		*ft_check(const char *sh, char *rh);
char		**ft_insplit(const char *str, char x);
void		ft_strfree2d(char **str);
int			strict_atoi(int *i_from_a, const char *argv);
int			strict_char_set(const char *str, const char *set);
int			validate_args(int argc, char **argv);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_chrinset(char r, char const *sset);
int			ft_strchrinset(char *t, char const *sset);
int			ft_chrsame(char a, char b);
int			ft_chrinset(char r, char const *sset);
int			ft_strchrinset(char *t, char const *sset);
int			ft_chrsame(char a, char b);
int			rgx_fun_in(int fun);
char		*rgx_chk_function(int mode, char *sh, char *blk);
void		rgx_maybe_free(char *blk, int fun);
int			ft_insp_count(char *h, char x);
int			rgx_function_n(char *rh);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strbegins(const char *str, const char *beg);
int			ft_strbeginsxl(char *str, char *beg);
char		*ft_inside(char *h);
void		rgx_set_rep(int *mm, char *mod);
char		*ft_inskip(char *h);
char		*rgx_sk_mod(char *mod);
char		*ft_findstr(char *str, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
size_t		ft_strarrlen(char **s);
int			ft_enclosure(char *io, char h);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			error_out(void);
t_stk		*init_stack_from_args(int argc, char **argv);
t_stk		*stack_init(char *stk_str);
void		stack_log(t_stk *stk);
void		destroy_stack(t_stk *stk);
char		*ft_itoa(int n);
char		*ft_strcat(const char *dst, const char *src);
char		*ft_strcatxl(char *s1, char *s2);
void		ft_print_stdout(const char *str);
void		ft_print_x(char *str);
t_stk		*stack_tail(t_stk *stk);
char		**ft_split(char const *s, char c);
int			stack_size(t_stk *stk);
void		stack_double_log(t_stk *a, t_stk *b);
char		*ft_strdup(const char *str);
char		*ft_strx(char *s1, char *s2);
char		*ft_strnew(void);
char		*ft_str(char *str);
void		*ft_xlloc(void *arg1, void *arg2);
void		*ft_x(void *a1, void *a2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcatxr(char *s1, char *s2);
char		*ft_strcatxx(char *s1, char *s2);
t_stk		*stack_chain_init(int argc, char **argv);
t_stk		*stack_chain_next(t_stk *stk);
t_stk		*stack_head(t_stk *stk);
char		*stack_double_log_level(t_stk *a, t_stk *b);
t_stk		*init_stack_empty(void);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		op_exec(char **ops, t_stk **a, t_stk **b);
char		*ft_strstr(const char *a, const char *b);
int			ft_stridentical(const char *s1, const char *s2);
void		sa(t_stk **a, t_stk **b);
void		sb(t_stk **a, t_stk **b);
void		ss(t_stk **a, t_stk **b);
void		pa(t_stk **a, t_stk **b);
void		pb(t_stk **a, t_stk **b);
void		ra(t_stk **a, t_stk **b);
void		rb(t_stk **a, t_stk **b);
void		rr(t_stk **a, t_stk **b);
void		rra(t_stk **a, t_stk **b);
void		rrb(t_stk **a, t_stk **b);
void		rrr(t_stk **a, t_stk **b);
t_stk		*cell_by_val(t_stk *s, int control);
void		switch_top(t_stk **s);
void		ft_print_x(char *str);
size_t		ft_strlen2d(char **s);
t_stk		*stack_clone(t_stk *s);
void		strategy_destroy(t_ttg *k);
void		op_run_str(char *o, t_stk **a, t_stk **b);
int			estas_finita(t_stk *a, t_stk *b);
void	ft_print_int(int i);
t_stk		*min_cell(t_stk *ss);
t_stk		*max_cell(t_stk *ss);
long			max_val(t_stk *ss);
int			in_order(t_stk *s);
int			in_reverse(t_stk *s);
int	deb_bol_(int i);
void	deb2(char *s);
void	deb_(char *s);
void	deb_int_(int i);

#endif
