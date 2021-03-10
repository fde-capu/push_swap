/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:05:05 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 18:07:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	reverse_rotate(t_stk **s)
{
	t_stk	*h;

	if (stack_size(*s) <= 1)
		return ;
	h = stack_tail(*s);
	h->pv->nx = 0;
	h->pv = 0;
	h->nx = (*s);
	h->nx->pv = h;
	(*s) = h;
	return ;
}

void	rra(t_stk **a, t_stk **b)
{ 
	reverse_rotate(a);
	(void)b;
	return ;
}

void	rrb(t_stk **a, t_stk **b)
{ 
	reverse_rotate(b);
	(void)a;
	return ;
}

void	rrr(t_stk **a, t_stk **b)
{ 
	reverse_rotate(a);
	reverse_rotate(b);
	return ;
}
