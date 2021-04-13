/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:48:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:28:50 by fde-capu         ###   ########.fr       */
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
	free(arg_str);
	return (o);
}

t_stk	*stack_nclone(t_stk *s, int n)
{
	char	*arg_str;
	t_stk	*o;

	if (!s)
		return (init_stack_empty());
	arg_str = ft_str("");
	while (s && n--)
	{
		arg_str = ft_strcatxx(arg_str, ft_itoa(s->val));
		if (s->nx)
			arg_str = ft_strcatxl(arg_str, ",");
		s = s->nx;
	}
	o = stack_init(arg_str);
	free(arg_str);
	return (o);
}
