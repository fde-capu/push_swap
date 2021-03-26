/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/26 16:33:37 by fde-capu         ###   ########.fr       */
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

int				lower_val(int a, int b)
{
	if (a <= b)
		return (a);
	if (b < a)
		return (b);
	return (0);
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	(void)o;
	deb_("Flush_ready? ");
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
	{
		deb_("Yes.\n");
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

int				abo_perfect_spot(t_abo abo)
{
	t_stk	*c;

	deb_("abo_perfect_spot? ");
	c = a_after_b(abo);
	if (c == *abo.a)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int				abo_combo_rewind(t_abo abo)
{
	deb_("abo Combo Rewind!\n");
	while (stack_size(*abo.b) > 0)
	{
		try_bubble_abo(abo, BTOA);
		if (!(abo_perfect_spot(abo)))
		{
			put_cell_on_top_b(abo.a, abo.b, abo.o, max_cell(*abo.b));
			put_cell_on_top_a(abo.a, abo.b, abo.o, a_after_b(abo));
		}
		ouch(abo.a, abo.b, abo.o, "pa");
	}
	shortest_rotation_a_flush(abo.a, abo.b, abo.o);
	return (estas_finita(*abo.a, *abo.b));
	return (-1);
}

int				flush_abo(t_abo abo)
{
	deb_("abo_Flush_ready? ");
	if (in_order_out_of_rot(*abo.a) && in_reverse_out_of_rot(*abo.b))
	{
		deb_("Yes.\n");
		return (abo_combo_rewind(abo));
	}
	deb_("No.\n");
	return (0);
}

char	*prev_command(char **h)
{
	char	*c;

	c = *h;
	if (*(c - 1) == ',')
		c -= 2;
	while (*c != ',')
		c--;
	c++;
	*h = c;
	deb_("last: ");
	deb_(*h);
	deb_("\n");
	return (*h);
}

void	moderate_shortest_rotation_b_receive(t_abo abo)
{
	int	c;
	char	*h;

	deb_("moderate_shortest_rotation_b_receive\n");
	c = calc_cell_on_top_b(abo.a, abo.b, abo.o, this_is_after_btoa(*abo.a, *abo.b));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h), "ra"))
			ouch_abo(abo, BTOA, "r_");
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h), "rra"))
			ouch_abo(abo, BTOA, "rr_");
	}
	return ;
}

int	pass_pivot_abo(t_abo abo, int dir, int len, int pivot)
{
	int		did;
	t_stk	*h;

	did = 0;
	h = ab_origin(abo, dir);
	while (h && h->nx && len--)
	{
//		if (!(count_le_len(ab_origin(abo, dir), pivot, len)))
		if (!(count_le(ab_origin(abo, dir), pivot)))
			break ;
		deb_("Try pass pivot for");
		deb_int_(h->val);
		deb_(", pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			moderate_shortest_rotation_b_receive(abo);
			ouch_abo(abo, pointer(dir), "p_");
			did++;
		}
		else
		{
			shortest_rotation_dir_pivot(abo, dir, pivot);
		}
//		if (flush_abo(abo))
//			return (did);
//		if (try_bubble_abo(abo, ATOB) && flush_abo(abo))
///			return (did);
		h = ab_origin(abo, dir);
	}
	deb_("End pass pivot.\n");
	return (did);
}

t_abo			make_abo(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;

	abo.a = a;
	abo.b = b;
	abo.o = o;
	return (abo);
}

int				reverse(int dir)
{
	if (dir == ATOB)
		return (BTOA);
	return (ATOB);
}

int				push_swap_sort(t_stk **a, t_stk **b, char **o, int dir)
{
	int		pivot;
	t_abo	abo;
	int		len;

//		gen_pivot_median(a, &pivot);
//		gen_pivot_last(a, &pivot);
	pivot = 0;
	abo = make_abo(a, b, o);
	len = stack_size(ab_origin(abo, dir));
	while (1)
	{
		if (flush_abo(abo))
			break ;
		if (try_bubble_abo(abo, dir) && flush_abo(abo))
			break ;
		gen_pivot_short(abo.a, &pivot);
		pass_pivot_abo(abo, dir, len, pivot);
		if (stack_size(ab_origin(abo, dir)) > 2)
		{
			put_cell_on_top_b(abo.a, abo.b, abo.o, max_cell(*abo.b));
			return (push_swap_sort(a, b, o, dir));
		}
		else
		{
			try_bubble_abo(abo, dir);
			return (abo_combo_rewind(abo));
		}
	}
	return (1);
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
//	quick_sort(a, b, o);
	push_swap_sort(a, b, o, ATOB);
	return ;
}
