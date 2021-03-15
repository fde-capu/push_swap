/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:41:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 12:48:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stk	*stack_init(char *stk_str)
{
	int		argc;
	char	**argv;
	t_stk	*out;

	stk_str = ft_strcat("foo,", stk_str);
	argv = ft_split(stk_str, ',');
	argc = ft_strlen2d(argv);
	out = init_stack_from_args(argc, argv);
	ft_strfree2d(argv);
	free (stk_str);
	return (out);
}

int			is_in_order(t_stk *s)
{
	int		control;

	if ((!s) || (stack_size(s) == 1))
		return (1);
	control = s->val;
	while (s)
	{
		if (s->val < control)
			return (0);
		if (s->val > control)
			control = s->val;
		s = s->nx;
	}
	return (1);
}

t_stk		*cell_by_val(t_stk *s, int control)
{
	while (s)
	{
		if (s->val == control)
			return (s);
		s = s->nx;
	}
	return (0);
}

t_stk		*min_cell(t_stk *ss)
{
	int		control;
	t_stk	*s;

	s = ss;
	control = s->val;
	while (s)
	{
		if (s->val < control)
			control = s->val;
		s = s->nx;
	}
	return (cell_by_val(ss, control));
}

char		*str_rot(int direction, int steps)
{
	char	*out;

	out = ft_str("");
	while (steps--)
	{
		if (direction == ASCEND)
			out = ft_strcatxl(out, ",r_");
		if (direction == DESCEND)
			out = ft_strcatxl(out, ",rr_");
	}
	return (out);
}

char		*easy_rot(t_stk *s, t_stk *h)
{
	t_stk	*h_up;
	t_stk	*h_dn;
	int		c_up;
	int		c_dn;

	(void)s;
	h_up = h;
	h_dn = h;
	c_up = 0;
	c_dn = 0;
	while (1)
	{
		if (!h_up->nx)
			return (str_rot(DESCEND, c_up));
		if (!h_dn->pv)
			return (str_rot(ASCEND, c_dn));
		h_up = h_up->nx;
		h_dn = h_dn->pv;
		c_up++;
		c_dn++;
	}
	return (ft_str(""));
}

void		str_replace_chr_chr(char **str, char this, char to_this)
{
	char	*h;

	h = *str;
	while (*h)
	{
		if (*h == this)
			*h = to_this;
		h++;
	}
	return ;
}

int			is_(t_stk *s)
{
	if (!s)
		return (0);
	return (1);
}

int			is_in_order_rot(t_stk *s, char **o, int exec, char ab)
{
	t_stk	*h;
	char	*tmp;
	int		loop;
	int		tst;

	if (!is_(s))
		return (0);
	h = min_cell(s);
	loop = stack_size(s);
	while (--loop)
	{
		tst = h->val;
		h = h->nx;
		if (!h)
			h = s;
		if (h->val < tst)
			return (0);
	}
	if (exec == EXEC)
	{
		tmp = easy_rot(s, h);
		str_replace_chr_chr(&tmp, '_', ab);
		*o = ft_strcatxx(*o, tmp);
	}
	return (1);
}

int			estas_finita(t_stk *a, t_stk *b)
{
	if (is_in_order(a) && !(stack_size(b)))
		return (1);
	return (0);
}
