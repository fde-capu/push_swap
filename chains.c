/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 09:21:11 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	deb_("Combo Rewind!\n");
	while (stack_size(*b) > 0)
	{
		ps_try_bubble(a, b, o);
		shortest_rotation_b_flush(a, b, o);
		shortest_rotation_a_receive(a, b, o);
		ouch(a, b, o, "pa");
	}
	shortest_rotation_a_flush(a, b, o);
	return (estas_finita(*a, *b));
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	(void)o;
	deb_("Flush_ready? ");
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
	{
		deb_("Yes.\n");
//		return (ps_combo_rewind(a, b, o));
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int	ps_pb_le_pivot(t_stk **a, t_stk **b, char **o, int pivot)
{
	t_stk	*h;
	int		did;

	did = 0;
	h = *a;
	while (h->nx)
	{
		if (!(count_le(*a, pivot)))
			break ;
		deb_("Try pb");
		deb_int_(h->val);
		deb_("pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			shortest_rotation_b_receive(a, b, o);
			did = ouch(a, b, o, "pb");
		}
		else
		{
			did = shortest_rotation_a_pivot(a, b, o, pivot);
		}
		if (ps_flush_ready(a, b, o))
			return (did);
		h = *a;
	}
	deb_("Partitioning finished.");
	return (did);
}

int				push_swap_sort(t_stk **a, t_stk **b, char **o)
{
	int		pivot;

//		gen_pivot_median(a, &pivot);
//		gen_pivot_last(a, &pivot);
	pivot = 0;
	while (1)
	{
		gen_pivot_short(a, &pivot);
		ps_try_bubble(a, b, o);
		if (ps_flush_ready(a, b, o))
			break ;
		if (ps_pb_le_pivot(a, b, o, pivot))
			continue ;
		if (ps_combo_rewind(a, b, o))
			break ;
		break ;
	}
	//		new_pivot = 1;
	if (ps_combo_rewind(a, b, o))
		return (1);
	return (0);
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
//	quick_sort(a, b, o);
	push_swap_sort(a, b, o);
	return ;
}
