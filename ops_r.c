/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:04:14 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 18:07:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate(t_stk **s)
{
	t_stk	*h;

	if (stack_size(*s) <= 1)
		return ;
	(*s)->pv = stack_tail(*s);
	h = (*s);
	(*s) = (*s)->nx;
	h->nx = 0;
	stack_tail(*s)->nx = h;
	(*s)->pv = 0;
	return ;
}

void	ra(t_stk **a, t_stk **b)
{ 
	rotate(a);
	(void)b;
	return ;
}

void	rb(t_stk **a, t_stk **b)
{ 
	rotate(b);
	(void)a;
	return ;
}

void	rr(t_stk **a, t_stk **b)
{ 
	rotate(a);
	rotate(b);
	return ;
}
