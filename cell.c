/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:05:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:16:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		val_before(t_stk *s, int med)
{
	int		ctl;
	t_stk	*h;

	ctl = min_val(s);
	h = s;
	while (h)
	{
		if (h->val > ctl && h->val < med)
			ctl = h->val;
		h = h->nx;
	}
	return (ctl);
}

int		val_after(t_stk *s, int med)
{
	int		ctl;
	t_stk	*h;

	ctl = max_val(s);
	h = s;
	while (h)
	{
		if (h->val < ctl && h->val > med)
			ctl = h->val;
		h = h->nx;
	}
	return (ctl);
}

t_stk	*cell_val_after(t_stk *s, t_stk *h)
{
	int	c;

	c = val_after(s, h->val);
	return (cell_by_val(s, c));
}

t_stk	*cell_val_before(t_stk *s, t_stk *h)
{
	int	c;

	c = val_before(s, h->val);
	return (cell_by_val(s, c));
}
