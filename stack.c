/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:48:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 14:00:35 by fde-capu         ###   ########.fr       */
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
	if (stk->empty)
		return (0);
	if (stk->nx)
		return (1 + stack_size(stk->nx));
	return (1);
}
