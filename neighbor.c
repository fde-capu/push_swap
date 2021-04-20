/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:27 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 21:06:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*a_after_b(t_abo abo)
{
	int		b;
	long	c;
	t_stk	*h;
	t_stk	*cell;

	if (!*abo.b)
		return (0);
	b = (*abo.b)->val;
	h = (*abo.a);
	c = (long)INT_MAX * (long)2;
	cell = 0;
	while (h)
	{
		if (h->val > b && h->val - b < c)
		{
			cell = h;
			c = h->val - b;
		}
		h = h->nx;
	}
	if (c == (long)INT_MAX * (long)2)
		cell = min_cell(*abo.a);
	return (cell);
}

t_stk	*b_before_a(t_abo abo)
{
	int		a;
	long	c;
	t_stk	*h;
	t_stk	*cell;

	if (!abo.b || !*abo.b)
		return (0);
	a = (*abo.a)->val;
	h = (*abo.b);
	c = (long)INT_MAX * (long)2;
	cell = 0;
	while (h)
	{
		if (h->val < a && a - h->val < c)
		{
			cell = h;
			c = a - h->val;
		}
		h = h->nx;
	}
	if (c == (long)INT_MAX * (long)2)
		cell = max_cell(*abo.b);
	return (cell);
}
