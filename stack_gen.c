/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:04:30 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:05:01 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stack_short(t_stk *s)
{
	t_stk	*tmp;
	t_stk	*tmp2;
	int		tiny;

	tmp = filter_le(s, stack_median(s)->val);
	tmp2 = filter_le(tmp, stack_median(tmp)->val);
	tiny = stack_median(tmp2)->val;
	destroy_stack(tmp);
	destroy_stack(tmp2);
	return (cell_by_val(s, tiny));
}

t_stk	*stack_median(t_stk *s)
{
	t_stk	*h;
	t_stk	*l;
	int		flip;

	flip = 0;
	h = max_cell(s);
	l = min_cell(s);
	while (h != l)
	{
		if (flip)
		{
			h = cell_val_before(s, h);
			flip = 0;
		}
		else
		{
			l = cell_val_after(s, l);
			flip = 1;
		}
	}
	return (l);
}
