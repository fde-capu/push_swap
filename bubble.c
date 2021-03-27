/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:29:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/27 13:40:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			may_bubble(t_stk *a, int dir)
{
	int	higher;
	int	lower;
	int	top;
	int	bot;
	int	med;

	if (!a || !a->nx)
		return (0);
	if (dir == ASCE)
	{
		higher = a->nx->val;
		lower = a->val;
	}
	if (dir == DESC)
	{
		higher = a->val;
		lower = a->nx->val;
	}
	top = max_val(a);
	bot = min_val(a);
	med = stack_median(a)->val;
	if ((dir == ASCE && higher == bot && lower == top)
	|| (dir == DESC && higher == bot && lower == top))
	{
		deb_("Case vertex. ");
		return (0);
	}
	if (higher > med && lower <= med)
	{
		deb_("No. ");
		return (0);
	}
	if (lower > higher)
		return (1);
	return (0);
}

int			may_bubble_abo(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (may_bubble(*abo.a, ASCE));
	if (dir == BTOA)
		return (may_bubble(*abo.b, DESC));
	return (0);
}

int				try_bubble_abo(t_abo abo, int dir)
{
	int		oa;
	int		ob;

	deb_("Try bubble abo. ");
	oa = may_bubble_abo(abo, dir);
	ob = may_bubble_abo(abo, pointer(dir));
	if (oa && ob)
	{
		ouch_abo(abo, dir, "ss");
		return (1);
	}
	if (oa)
	{
		ouch_abo(abo, dir, "s_");
		return (1);
	}
	if (ob)
	{
		ouch_abo(abo, pointer(dir), "s_");
		return (1);
	}
	deb_("No.\n");
	return (0);
}
