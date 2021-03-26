/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:29:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 14:33:45 by fde-capu         ###   ########.fr       */
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
	if ((higher > med && lower <= med) || (higher > med && lower <= med))
	{
		deb_("case 1.\n");
		return (0);
	}
	if (dir == ASCE && higher == bot && lower == top)
	{
		deb_("case 2.\n");
		return (0);
	}
	if (lower > higher)
		return (1);
	deb_("case 3.\n");
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

int				ps_try_bubble(t_stk **a, t_stk **b, char **o)
{
	int		oa;
	int		ob;

	deb_("Try bubble. ");
	oa = may_bubble(*a, ASCE);
	ob = may_bubble(*b, DESC);
	if (oa && ob)
		return (ouch(a, b, o, "ss"));
	if (oa)
		return (ouch(a, b, o, "sa"));
	if (ob)
		return (ouch(a, b, o, "sb"));
	deb_("No.\n");
	return (0);
}

int	bubble_and_flush(t_stk **a, t_stk **b, char **o)
{
	ps_try_bubble(a, b, o);
	return (ps_flush_ready(a, b, o));
}
