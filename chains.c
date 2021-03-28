/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/28 12:24:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ouch(abo.a, abo.b, abo.o, *h);
		h++;
	}
	ft_strfree2d(lst);
	return ;
}

int	abox(t_abo abo)
{
	deb_(*abo.o);
	deb_("\n---\n");
//	write(1, "test", 4);
	deb_(*abo.o);
	deb_("\n");
//	destroy_stack(*abo.a);
//	destroy_stack(*abo.b);
//	free(*abo.o);
	exit(-2);
	return (1);
}

t_abo	*abodup(t_abo abo)
{
	t_stk	*s[2];
	t_abo	*cp;
	char	*cpo;

	s[0] = stack_clone(*abo.a);
	s[1] = stack_clone(*abo.b);
	cpo = ft_str(*abo.o);
	cp = malloc(sizeof(t_abo));
	cp->a = &s[0];
	cp->b = &s[1];
	cp->o = &cpo;
	return (cp);
}

char	*best_rewind(t_abo abo)
{
	t_abo	*loc;

	deb_("best_rewind.\n");
	loc = abodup(abo);
	ft_print_stdout("\n\nxXx\n\n");
	stack_log(*loc->a);
//	ft_print_stdout("\n\nxXx\n\n");
//	deb_("\n\n_x_\n\n");
	sleep(2);
	stack_log(*loc->a);
	deb_("\n\n---\n\n");
	exit (-2);
//	*loc.o = ft_x(*loc.o, ft_str(""));
//	if (abo_perfect_spot(abo) && abox(abo))
//		return (0);
	abox(*loc);
	return (0);
}

int				abo_combo_rewind(t_abo abo)
{
//	static int	strategy = 2;

	deb_("abo Combo Rewind!\n");
	while (stack_size(*abo.b) > 0)
	{
		bubble(abo);
		if (!(abo_perfect_spot(abo)))
		{
			re_ouch(abo, best_rewind(abo));
//			if (strategy == 1)
//			{
//				put_cell_on_top_b(abo.a, abo.b, abo.o, \
//					max_cell(*abo.b));
//				put_cell_on_top_a(abo.a, abo.b, abo.o, \
//					a_after_b(abo));
//			}
//			if (strategy == 2)
//			{
//				put_cell_on_top_a(abo.a, abo.b, abo.o, \
//					a_after_b(abo));
//			}
		}
		ouch(abo.a, abo.b, abo.o, "pa");
	}
	shortest_rotation_a_flush(abo.a, abo.b, abo.o);
	return (estas_finita(*abo.a, *abo.b));
	return (-1);
}

int				flush(t_abo abo)
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
			exec(abo, "rb");
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h), "rra"))
			exec(abo, "rrb");
	}
	return ;
}

int	partition(t_abo abo, int len, int pivot)
{
	int		did;
	t_stk	*h;

	did = 0;
	h = *abo.a;
	while (h && h->nx && len--)
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
//		if (flush(abo))
//			return (did);
//		if (bubble(abo) && flush(abo))
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
	int		len;

//		gen_pivot_median(a, &pivot);
//		gen_pivot_last(a, &pivot);
	pivot = 0;
	abo = make_abo(a, b, o);
	len = stack_size(*abo.a);
	while (1)
	{
		if (flush(abo))
			break ;
		if (bubble(abo) && flush(abo))
			break ;
		gen_pivot_short(abo.a, &pivot);
		partition(abo, len, pivot);
		if (stack_size(*abo.a) > 2)
		{
			put_cell_on_top_b(abo.a, abo.b, abo.o, max_cell(*abo.b));
			return (push_swap_sort(a, b, o));
		}
		else
		{
			bubble(abo);
			return (abo_combo_rewind(abo));
		}
	}
	return (1);
}
