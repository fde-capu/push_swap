/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:00:49 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:32:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gen_pivot_last(t_stk **a, int *pivot)
{
	*pivot = stack_tail(*a)->val;
	return ;
}

void	gen_pivot_short(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_short(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	return ;
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

int		piv_higher(t_stk *cell, int pivot[4])
{
	if (!cell)
		return (1);
	deb_int_(cell->val);
	deb_(":");
	deb_quad_pivot(pivot);
	deb_("HIGH? ");
	if (cell && is_in_range(cell->val, pivot[2], pivot[3]))
		return (deb_bol_(1));
	return (deb_bol_(0));
}

int		piv_lower(t_stk *cell, int pivot[4])
{
	if (!cell)
		return (1);
	deb_int_(cell->val);
	deb_(":");
	deb_quad_pivot(pivot);
	deb_("LOW? ");
	if (cell && is_in_range(cell->val, pivot[0], pivot[1]))
		return (deb_bol_(1));
	return (deb_bol_(0));
}
