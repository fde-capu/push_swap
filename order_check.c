/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:57:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/18 10:08:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int			estas_finita(t_stk *a, t_stk *b)
{
	if (in_order(a) && !(stack_size(b)))
		return (1);
	return (0);
}

int			in_order(t_stk *s)
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

int			in_reverse(t_stk *s)
{
	int		control;

	if ((!s) || (stack_size(s) == 1))
		return (1);
	control = s->val;
	while (s)
	{
		if (s->val > control)
			return (0);
		if (s->val < control)
			control = s->val;
		s = s->nx;
	}
	return (1);
}

int				in_order_out_of_rot(t_stk *a)
{
	int		loop;
	t_stk	*h;
	int		prev;

	loop = stack_size(a);
	if (loop <= 1)
		return (1);
	h = min_cell(a);
	while (loop--)
	{
		prev = h->val;
		h = h->nx;
		if (!h)
			h = a;
		if ((h->val < prev) && (h != min_cell(a)))
			return (0);
	}
	return (1);
}

int				in_reverse_out_of_rot(t_stk *a)
{
	int		loop;
	t_stk	*h;
	int		prev;

	loop = stack_size(a);
	if (loop <= 1)
		return (1);
	h = max_cell(a);
	while (loop--)
	{
		prev = h->val;
		h = h->nx;
		if (!h)
			h = a;
		if ((h->val > prev) && (h != max_cell(a)))
			return (0);
	}
	return (1);
}
