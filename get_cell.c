/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 10:06:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 14:57:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

long		max_val(t_stk *ss)
{
	int		control;
	t_stk	*s;

	s = ss;
	if (!ss)
		return ((long)INT_MIN - 1);
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
	long		control;

	control = max_val(ss);
	if (control == (long)INT_MIN - 1)
		return (0);
	return (cell_by_val(ss, (int)control));
}
