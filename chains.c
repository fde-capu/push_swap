/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 02:52:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			flush_final(t_abo abo)
{
	deb_("flush_final? ");
	if (in_order_out_of_rot(*abo.a) && in_reverse_out_of_rot(*abo.b))
	{
		deb_("Yes.\n");
		return (master_rewind(abo));
	}
	deb_("No.\n");
	return (0);
}

int			master_rewind(t_abo abo)
{
	deb_("abo Combo Rewind!\n");
	while (stack_size(*abo.b) > 0)
	{
		bubble(abo);
		top_a(abo, a_after_b(abo));
		top_b(abo, max_cell(*abo.b));
		ouch(abo.a, abo.b, abo.o, "pa");
	}
	flush_a(abo);
	return (estas_finita(*abo.a, *abo.b));
}

int			any_below_pivot(t_abo abo, int pivot)
{
	t_stk	*h;

	h = *abo.a;
	while (h)
	{
		if (h->val <= pivot)
			return (1);
		h = h->nx;
	}
	return (0);
}

void		simple_partition(t_abo abo, int pivot)
{
	while (any_below_pivot(abo, pivot))
	{
		if ((*abo.a)->val <= pivot)
			rot_b_pb(abo);
		else
			shortest_a_atob(abo, pivot);
	}
	return ;
}

int			push_swap_sort(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;
	int		pivot;

	abo = make_abo(a, b, o);
	pivot = 0;
	while (stack_size(*abo.a) > 2)
	{
		if (bubble(abo) && flush_final(abo))
			break ;
		else
		{
			if (flush_final(abo))
				break ;
		}
		gen_pivot_short(abo.a, &pivot);
		deb_int_(pivot);
		simple_partition(abo, pivot);
	}
	return (master_rewind(abo));
}
