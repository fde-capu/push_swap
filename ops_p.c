/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:03:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 10:56:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push_top(t_stk **d, t_stk **s)
{
	t_stk	*h;

	if (!(*s))
		return ;
	h = (*s);
	(*s) = (*s)->nx;
	if (*s)
		(*s)->pv = 0;
	h->nx = (*d);
	if (*d)
		(*d)->pv = h;
	(*d) = h;
	return ;
}

void	pa(t_stk **a, t_stk **b)
{
	push_top(a, b);
	return ;
}

void	pb(t_stk **a, t_stk **b)
{
	push_top(b, a);
	return ;
}
