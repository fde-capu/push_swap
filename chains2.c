/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:57:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/27 13:36:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			may_bubble_abo_nx(t_abo abo, int dir)
{
	if (dir == ATOB && (!abo.a || !(*abo.a)->nx))
		return (0);
	if (dir == BTOA && (!abo.b || !(*abo.b)->nx))
		return (0);
	if (dir == ATOB && (*abo.a)->nx->val > (*abo.a)->nx->nx->val)
			return (1);
	if (dir == BTOA && (*abo.b)->nx->val < (*abo.b)->nx->nx->val)
			return (1);
	return (0);
}

t_stk	*stack_x(t_stk *old, t_stk *new)
{
	destroy_stack(old);
	return (new);
}

char	*op_(char *mask, int dir)
{
	char	*o;
	char	*h;

	o = ft_str(mask);
	h = o;
	while (*h)
	{
		if (*h == '_')
		{
			if (dir == ATOB)
				*h = 'a';
			if (dir == BTOA)
				*h = 'b';
		}
		h++;
	}
	return (o);
}

void	ouch_abo(t_abo abo, int dir, char *mask)
{
	char	*op;

	op = op_(mask, dir);
	ouch(abo.a, abo.b, abo.o, op);
	free (op);
	return ;
}

int		pointer(int dir)
{
	if (dir == ATOB)
		return (BTOA);
	if (dir == BTOA)
		return (ATOB);
	return (-1);
}

t_stk	*ab_destiny(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (*abo.b);
	if (dir == BTOA)
		return (*abo.a);
	return (0);
}

t_stk	*ab_origin(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (*abo.a);
	if (dir == BTOA)
		return (*abo.b);
	return (0);
}

