/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 21:30:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		count_gt(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val > about)
		return (count_gt(h->nx, about) + 1);
	else
		return (count_gt(h->nx, about));
}

int		count_le(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val <= about)
		return (count_le(h->nx, about) + 1);
	else
		return (count_le(h->nx, about));
}

int		all_lowereq(t_stk *h, int about)
{
	while (h)
	{
		if (h->val > about)
			return (0);
		h = h->nx;
	}
	return (1);
}

void	get_put_dump(t_stk **a, t_stk **b, char **o)
{
	while (*b)
	{
		*o = ft_strcatxl(*o, ",pa");
		pa(a, b);
	}
	return ;
}

void	ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, a, b);
	printf("LOG %s\n", op);
	stack_double_log(*a, *b);
}

char	*rot_favor_less_steps(t_stk *s, int th)
{
	int	c_up;
	int	c_dn;

	c_up = 0;
	while (s)
	{
		if (s->val > th)
			break ;
		c_up++;
		s = s->nx;
	}
	s = stack_tail(s);
	c_dn = 1;
	while (s)
	{
		if (s->val > th)
			break ;
		c_dn++;
		s = s->pv;
	}
	if (c_up < c_dn)
		return (ft_str("ra"));
	else
		return (ft_str("rra"));
}

char	*rot_favor_sequencing(t_stk *s, int th)
{
	int	c_up;
	int	c_dn;
	int	tmp;

	c_up = 0;
	c_dn = 0;
	while (s)
	{
		tmp = s->val;
		s = s->nx;
		if (tmp <= th)
			continue ;
		if (!s)
			break ;
		if (s->val > tmp)
			c_up++;
		else
			c_dn++;
	}
	if (c_up > c_dn)
		return (ft_str("ra"));
	else
		return (ft_str("rra"));
}

char	*best_rot_dir_for_split(t_stk *s, int th)
{
	int	c_gt;

	c_gt = count_gt(s, th);
	if (c_gt > stack_size(s) / 2)
		return (rot_favor_sequencing(s, th));
	else
		return (rot_favor_less_steps(s, th));
}

void	gen_split_low_high(t_stk **a, t_stk **b, int about, char **o)
{
	t_stk	*h;
	char	*str_dir;

	h = *a;
	str_dir = best_rot_dir_for_split(h, about);
	while (!(all_lowereq(h, about)))
	{
		if (h->val > about)
			ouch(a, b, o, "pb");
		else
			ouch(a, b, o, str_dir);
		h = *a;
	}
	free (str_dir);
	return ;
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

int			min_val(t_stk *ss)
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
	return (control);
}

int			max_val(t_stk *ss)
{
	int		control;
	t_stk	*s;

	s = ss;
	control = s->val;
	while (s)
	{
		if (s->val > control)
			control = s->val;
		s = s->nx;
	}
	return (control);
}

t_stk		*min_cell(t_stk *ss)
{
	int		control;

	control = min_val(ss);
	return (cell_by_val(ss, control));
}

t_stk		*max_cell(t_stk *ss)
{
	int		control;

	control = max_val(ss);
	return (cell_by_val(ss, control));
}
