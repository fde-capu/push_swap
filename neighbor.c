/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:27 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 17:59:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk			*this_is_after(t_stk *a, t_stk *b)
{
	t_stk	*h;
	t_stk	*after;
	int		once;

	deb_("What should succed");
	deb_int_(a->val);
	deb_("? >");
	if (stack_size(b) <= 1)
		return (b);
	after = 0;
	once = 1;
	h = b;
	while (h)
	{
		if (h->val < a->val)
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
		after = max_cell(b);
	deb_int_(after->val);
	deb_("\n");
	return (after);
}

t_stk			*this_is_before(t_stk *a, t_stk *b)
{
	t_stk	*h;
	t_stk	*before;
	int		once;

	deb_("What should preceed");
	deb_int_(b->val);
	deb_("? <");
	if (stack_size(a) <= 1)
		return (a);
	once = 1;
	h = a;
	while (h)
	{
		if (h->val > b->val)
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
