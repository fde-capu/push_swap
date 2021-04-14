/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:29:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 13:27:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			set_lower_higher(t_stk *a, int dir, int *lower, int *higher)
{
	if (dir == ASCE)
	{
		*higher = a->nx->val;
		*lower = a->val;
	}
	if (dir == DESC)
	{
		*higher = a->val;
		*lower = a->nx->val;
	}
	return ;
}

int				may_bubble(t_stk *a, int dir)
{
	int	higher;
	int	lower;
	int	med;

	if (!a || !a->nx)
		return (0);
	set_lower_higher(a, dir, &lower, &higher);
	med = stack_median(a)->val;
	if ((dir == ASCE && higher == min_val(a) && lower == max_val(a))
	|| (dir == DESC && higher == min_val(a) && lower == max_val(a)))
	{
		if (stack_size(a) == 2)
			return (1);
		return (0);
	}
	if (higher > med && lower <= med)
		return (0);
	if (lower > higher)
		return (1);
	return (0);
}

int				bubble(t_abo abo)
{
	int		oa;
	int		ob;

	deb_("Bubble: ");
	oa = may_bubble(*abo.a, ASCE);
	ob = may_bubble(*abo.b, DESC);
	if (oa && ob)
	{
		exec(abo, "ss");
		return (1);
	}
	if (oa)
	{
		exec(abo, "sa");
		return (1);
	}
	if (ob)
	{
		exec(abo, "sb");
		return (1);
	}
	return (0);
}
