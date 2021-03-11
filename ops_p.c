/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:03:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 23:18:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	push_top(t_stk **dst, t_stk **src)
{
	t_stk	*h;

	if (!(*src))
		return ;
	h = (*src);
	(*src) = (*src)->nx;
	h->nx = (*dst);
	if (*dst)
		(*dst)->pv = h;
	(*dst) = h;
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
