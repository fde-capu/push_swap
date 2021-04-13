/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 14:23:49 by fde-capu         ###   ########.fr       */
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
	int	c;

	deb_("Master Rewind\n");
	c = 0;
	while (stack_size(*abo.b))
	{
		opportunistic_flush_b(abo);
		if (shortest_a_btoa(abo))
			exec(abo, "pa");
	}
	flush_a(abo);
	deb_("\nFinal:\n\n");
	deb_stack_double_log(*abo.a, *abo.b);
	return (estas_finita(*abo.a, *abo.b));
}

int			simple_partition(t_abo abo, int pivot[4])
{
	static t_stk	*hodlr;
	static int		hold;

	top_b(abo, hodlr);
	hold = 0;
	while (any_in_quad_pivot(abo, pivot) && stack_size(*abo.a) > 2)
	{
		full_rot_a_quad(abo, pivot);
		if (stack_size(*abo.b) < stack_size(*abo.a) * 4 / 3)
			rot_b_pb(abo);
		else
		{
			moderate_shortest_rotation_b_receive(abo);
			if (piv_lower(*abo.a, pivot))
				hold = 1;
			if ((piv_higher(*abo.a, pivot)) && (hold == 1 && hodlr))
				top_b(abo, hodlr);
			exec(abo, "pb");
			if (piv_higher(*abo.b, pivot) && (hodlr = *abo.b))
				hold = 0;
		}
	}
	return (1);
}

void		four_zeroes(int pivot[4])
{
	return ;
	pivot[0] = 0;
	pivot[1] = 0;
	pivot[2] = 0;
	pivot[3] = 0;
}

int			push_swap_sort(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;
	int		pivot[4];

	four_zeroes(pivot);
	abo = make_abo(a, b, o);
	gen_pivot_soft_quad_sand(*a, pivot, soft_slice(abo));
	deb_quad_pivot(pivot);
	if (flush_final(abo))
		return (1);
	while (1)
	{
		if (bubble(abo) && flush_final(abo))
			break ;
		else
		{
			if (flush_final(abo))
				break ;
		}
		simple_partition(abo, pivot);
		if (stack_size(*abo.a) > 2)
			return (push_swap_sort(a, b, o));
		else
			return (master_rewind(abo));
	}
	return (1);
}
