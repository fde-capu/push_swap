/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:48:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/17 17:28:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stk	*stack_head(t_stk *stk)
{
	if (stk->pv)
		return (stack_head(stk->pv));
	return (stk);
}

t_stk	*stack_tail(t_stk *stk)
{
	if (stk->nx)
		return (stack_tail(stk->nx));
	return (stk);
}

t_stk	*stack_median(t_stk *s)
{
	t_stk	*h;
	int		le;
	int		gt;
	int		test;
	int		best;
	t_stk	*median;

	best = INT_MAX;
	h = s;
	while (h)
	{
		le = count_le(s, h->val);
		gt = count_gt(s, h->val);
		test = le - gt - 1;
		if (test < 0)
			test *= -1;
		if (test < best)
		{
			median = h;
			best = test;
		}
		h = h->nx;
	}
	return (median);
}

int		stack_size(t_stk *stk)
{
	if (!stk)
		return (0);
	if (stk->nx)
		return (1 + stack_size(stk->nx));
	return (1);
}

t_stk	*stack_clone(t_stk *s)
{
	char	*arg_str;
	t_stk	*o;

	if (!s)
		return (init_stack_empty());
	arg_str = ft_str("");
	while (s)
	{
		arg_str = ft_strcatxx(arg_str, ft_itoa(s->val)); 
		if (s->nx)
			arg_str = ft_strcatxl(arg_str, ",");
		s = s->nx;
	}
	o = stack_init(arg_str);
	free (arg_str);
	return (o);
}
