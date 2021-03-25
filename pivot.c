/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 16:28:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		gen_pivot_last(t_stk **a, int *pivot)
{
	*pivot = stack_tail(*a)->val;
	return ;
}

void		gen_pivot_median(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_median(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}

void		gen_pivot_short(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_short(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}

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
	int		le;
	int		gt;
	int		test;
	int		best;
	t_stk	*median;

	best = INT_MAX;
	h = s;
	while (h)
	{
		le = count_le(s, h->val);
		gt = count_gt(s, h->val);
		test = le - gt - 1;
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
