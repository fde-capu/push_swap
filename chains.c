/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/29 15:54:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				perfect_spot(t_abo abo)
{
	t_stk	*c;

	deb_("perfect_spot? ");
	c = a_after_b(abo);
	if (c == *abo.a)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

void	re_ouch(t_abo abo, char *ops)
{
	char	**lst;
	char	**h;
	
	if (!ops || !*ops)
		return ;
	lst = ft_split(ops, ',');
	h = lst;
	while (*h)
	{
		exec(abo, *h);
		h++;
	}
	ft_strfree2d(lst);
	return ;
}

char		*clear_ret(t_abo abo, char *ret)
{
	destroy_stack(*abo.a);
	destroy_stack(*abo.b);
	free(*abo.o);
	return (ret);
}

char	*best_rewind(t_abo abo)
{
	t_abo	loc;
	t_stk	*ta;
	t_stk	*tb;
	char	*to;
	int		c;

	deb_("best_rewind : ");
	if (perfect_spot(abo))
		return (0);
	loc = abo;
	ta = stack_clone(*abo.a);
	loc.a = &ta;
	tb = stack_clone(*abo.b);
	loc.b = &tb;
	to = ft_str("pb,pb,ss,pa");
	loc.o = &to;
	*loc.o = to;

	c = count_instructions_in_str(*loc.o);
	deb_("\nloco:");
	deb_(*loc.o);
	deb_("\nc:");
	deb_int_(c);
//	exec(loc, "pa");

	return (clear_ret(loc, ft_str(*loc.o)));
}

int				combo_rewind(t_abo abo)
{
	char	*o;

	deb_("Combo Rewind!\n");
	while (stack_size(*abo.b) > 0)
	{
		o = best_rewind(abo);
		deb_("Best: '");
		deb_(o);
		deb_("'\n");
//		if (strategy == 1)
//		{
//			top_b(abo, \
//				max_cell(*abo.b));
//			top_b(abo, \
//				a_after_b(abo));
//		}
//		if (strategy == 2)
//		{
//			top_b(abo, \
//				a_after_b(abo));
//		}
		re_ouch(abo, o);
		free(o);
		exec(abo, "pa");
	}
	flush_a(abo);
	return (estas_finita(*abo.a, *abo.b));
}

int				flush_final(t_abo abo)
{
	deb_("flush_final? ");
	if (in_order_out_of_rot(*abo.a) && in_reverse_out_of_rot(*abo.b))
	{
		deb_("Yes.\n");
		return (combo_rewind(abo));
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
	return (*h);
}

void	moderate_shortest_rotation_b_receive(t_abo abo)
{
	int	c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return ;
	deb_("moderate_shortest_rotation_b_receive\n");
	c = calc_top_b(abo, this_is_after_btoa(abo));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h), "ra"))
			exec(abo, "rb");
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h), "rra"))
			exec(abo, "rrb");
	}
	return ;
}

int	partition(t_abo abo, int pivot)
{
	int		did;
	t_stk	*h;

	did = 0;
	h = *abo.a;
	while (h && h->nx)
	{
		if (!(count_le(h, pivot)))
			break ;
		deb_("Try pass pivot for");
		deb_int_(h->val);
		deb_(", pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			moderate_shortest_rotation_b_receive(abo);
			exec(abo, "pb");
			did++;
		}
		else
		{
			shortest_rotation_a_pivot(abo, pivot);
		}
//		if (flush_final(abo))
//			return (did);
//		if (bubble(abo) && flush_final(abo))
///			return (did);
		h = *abo.a;
	}
	deb_("...end pass pivot.\n");
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

int		push_swap_sort(t_stk **a, t_stk **b, char **o)
{
	int		pivot;
	t_abo	abo;

//		gen_pivot_median(a, &pivot);
//		gen_pivot_last(a, &pivot);
	pivot = 0;
	abo = make_abo(a, b, o);
	if (flush_final(abo))
		return (1);
	while (1)
	{
		if (bubble(abo) && flush_final(abo))
			break ;
		gen_pivot_short(abo.a, &pivot);
		partition(abo, pivot);
		if (stack_size(*abo.a) > 2)
		{
//			static int d = 0; if (d++ == 3) exit (0);
			return (push_swap_sort(a, b, o));
		}
		else
		{
			return (combo_rewind(abo));
		}
	}
	return (1);
}
