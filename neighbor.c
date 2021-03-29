/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:27 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/29 16:21:06 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk			*this_is_after_btoa(t_abo abo)
{
	t_stk	*h;
	t_stk	*after;
	int		once;

	deb_("What should succed");
	deb_int_((*abo.a)->val);
	deb_("? >");
	if (stack_size(*abo.b) <= 1)
		return (*abo.b);
	after = 0;
	once = 1;
	h = *abo.b;
	while (h)
	{
		if (h->val < (*abo.a)->val)
		{
			if (once)
			{
				after = h;
				once = 0;
			}
			if (h->val > after->val)
			{
				after = h;
			}
		}
		h = h->nx;
	}
	if (!after)
		after = max_cell(*abo.b);
	deb_int_(after->val);
	deb_("\n");
	return (after);
}

t_stk			*this_is_before_atob(t_abo abo)
{
	t_stk	*h;
	t_stk	*before;
	int		once;

	deb_("What should preceed");
	deb_int_((*abo.b)->val);
	deb_("? <");
	if (stack_size(*abo.a) <= 1)
		return (*abo.a);
	once = 1;
	h = *abo.a;
	while (h)
	{
		if (h->val > (*abo.b)->val)
		{
			if (once)
			{
				before = h;
				once = 0;
			}
			if (h->val < before->val)
			{
				before = h;
			}
		}
		h = h->nx;
	}
	deb_int_(before->val);
	deb_("\n");
	return (before);
}

t_stk		*a_after_b(t_abo abo)
{
	int		b;
	long	c;
	t_stk	*h;
	t_stk	*cell;

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
	deb_("(rot 'a' until");
	deb_int_(cell->val);
	deb_("to receive");
	deb_int_(b);
	deb_(") ");
	return (cell);
}

t_stk		*b_before_a(t_abo abo)
{
	int		a;
	long	c;
	t_stk	*h;
	t_stk	*cell;

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
		cell = min_cell(*abo.b);
	deb_("rot 'b' until");
	deb_int_(cell->val);
	deb_("to put over");
	deb_int_(a);
	deb_("\n");
	return (cell);
}
