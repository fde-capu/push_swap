/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:17:04 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 14:45:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>





# include <stdio.h>





typedef struct			s_stack
{
	int					val;
	struct s_stack		*nx;
	struct s_stack		*pv;
}						t_stk;

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrimx(char *s1, char *set);
int			init_arg(t_stk **arg_dst, char *argv);
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
void		error_out(void);
t_stk		*init_stack(int argc, char **argv);
void		stack_log(t_stk *stk);
int			end_routine(t_stk *stack_a);
void		destroy_stack(t_stk *stk);
char		*ft_itoa(int n);
char		*ft_strcat(const char *dst, const char *src);
char		*ft_strcatxl(char *s1, char *s2);
void		ft_print_stdout(const char *str);
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

# define TRIM_SET	" \t\n\r\v\f"

/*
** ft_check related:
*/

# define REG_DOUBLE				"-?\\d+\\.?\\d*"
# define REG_UDOUBLE			"\\d+\\.?\\d*"
# define FUN_DIG				1
# define FUN_PAR				2
# define FUN_SET				3
# define FUN_CHR				4
# define ENCLOSURES				"()[]{}"
# define ENCLOSE_OPEN			"([{"

#endif
