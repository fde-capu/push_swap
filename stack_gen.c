/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:04:30 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 02:41:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stack_short(t_stk *s)
{
	t_stk	*tmp;
	int		tiny;

	tmp = filter_le(s, stack_median(s)->val);
	tiny = stack_median(tmp)->val;
	destroy_stack(tmp);
	return (cell_by_val(s, tiny));
}

t_stk	*stack_median(t_stk *s)
{
	t_stk	*h;
	int		le_gt[2];
	int		test;
	int		best;
	t_stk	*median;

	best = INT_MAX;
	h = s;
	while (h)
	{
		le_gt[0] = count_le(s, h->val);
		le_gt[1] = count_gt(s, h->val);
		test = le_gt[0] - le_gt[1] - 1;
		if (test < 0)
			test *= -1;
		if (test < best)
		{
			median = h;
			best = test;
		}
		h = h->nx;
	}
	return (median);
}
