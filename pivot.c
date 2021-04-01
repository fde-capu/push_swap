/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/01 13:00:46 by fde-capu         ###   ########.fr       */
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

t_stk	*filter_le(t_stk *s, int control)
{
	t_stk	*xa;
	t_stk	*xb;

	xa = stack_clone(s);
	xb = init_stack_empty();
	while (count_le(xa, control))
	{
		if (xa->val <= control)
			op_run_str("pb", &xa, &xb);
		else
			op_run_str("ra", &xa, &xb);
	}
	destroy_stack(xa);
	return (xb);
}

void	gen_pivot_slice(t_stk *s, int *pivot, int slices)
{
	static int	size = -1;
	t_stk		*h;
	t_stk		*xa;
	t_stk		*xb;

	if (size == -1)
		size = stack_size(s) / slices;
	if (stack_size(s) <= size || size < 3)
	{
		*pivot = stack_median(s)->val;
		return ;
	}
	if (size > 45)
		size = 45;
	xa = stack_clone(s);
	xb = init_stack_empty();
	while (stack_size(xb) < size)
	{
		h = min_cell(xa);
		while (xa != h)
			op_run_str("ra", &xa, &xb);
		op_run_str("pb", &xa, &xb);
	}
	h = cell_by_val(s, max_cell(xb)->val);
	destroy_stack(xa);
	destroy_stack(xb);
	*pivot = h->val;
	deb_pivot(*pivot);
	return ;
}
