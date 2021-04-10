/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/10 03:51:41 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char		*clear_ret(t_abo abo[TEST_NUM], char *ret)
{
	int	i;

	i = -1;
	while (++i < TEST_NUM)
	{
		destroy_stack(*abo[i].a);
		destroy_stack(*abo[i].b);
		free(*abo[i].o);
	}
	return (ret);
}

int		pa_count(t_abo loc)
{
	char	*h;
	int		pac;

	pac = 0;
	h = *loc.o;
	while (*h)
	{
		if (ft_strbegins(h, "pa"))
			pac++;
		next_command(&h);
	}
	return (pac);
}

char	*lower_c_loc_o(int c[TEST_NUM], t_abo loc[TEST_NUM])
{
	int		i;
	double	control;
	char	*o;
	int		pac;

	o = ft_str("");
	control = 0;
	i = -1;
	while (++i < TEST_NUM)
	{
		pac = pa_count(loc[i]) + 1;
		if ((double)pac / (double)c[i] > control)
		{
			control = (double)pac / (double)c[i];
			o = ft_x(o, ft_str(*loc[i].o));
		}
	}
	return (o);
}

char	*best_rewind(t_abo abo)
{
	t_abo	loc[TEST_NUM];
	t_stk	*ta[TEST_NUM];
	t_stk	*tb[TEST_NUM];
	char	*to[TEST_NUM];
	int		c[TEST_NUM];
	int		i;

	if (stack_size(*abo.b) == 0)
		return (ft_str(""));
	if (spot_dn(abo))
		return (ft_str("pa"));
	deb_("\nBest Rewind");
	deb_(":\n");
	i = -1;
	while (++i < TEST_NUM)
	{
		loc[i] = abo;
		ta[i] = stack_clone(*abo.a);
		loc[i].a = &ta[i];
		tb[i] = stack_clone(*abo.b);
		loc[i].b = &tb[i];
		to[i] = ft_str("");
		loc[i].o = &to[i];
		*loc[i].o = to[i];
	}
	s_2_(loc[0]);
//	s_2_(loc[1]);
//	s_3_(loc[2]);
//	s_4_(loc[3]);
	treat_loc_redundancies(loc);
	count_loc_instructions(c, loc);
	return (clear_ret(loc, lower_c_loc_o(c, loc)));
}

int	path_complexity(t_stk *s)
{
	t_stk	*h;
	int		o;
	int		t;

	o = 0;
	h = s;
	while (h->nx)
	{
		t = h->nx->val - h->val;
		t *= t < 0 ? -1 : 1;
		o += t;
		h = h->nx;
	}
	t = s->val - h->val;
	t *= t < 0 ? -1 : 1;
	o += t;
	return (o);
}

t_abo			make_abo(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;

	abo.a = a;
	abo.b = b;
	abo.o = o;
	return (abo);
}

void	bubble_put(t_abo abo)
{
	while (stack_size(*abo.b) < 2)
		exec(abo, "pb");
	while (stack_size(*abo.a) > 2)
	{
		bubble(abo);
		exec(abo, "pb");
	}
	return ;
}

void	bubble_cycle(t_abo abo)
{
	bubble_put(abo);
	while (stack_size(*abo.a) < 2)
		exec(abo, "pa");
	while (stack_size(*abo.b) > 2)
	{
		bubble(abo);
		exec(abo, "pa");
	}
	return ;
}

int	partition(t_abo abo, int pivot)
{
	t_stk	*h;

	while (count_le(*abo.a, pivot))
	{
		h = *abo.a;
		deb_("Try pass pivot for");
		deb_int_(h->val);
		deb_(", pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			exec(abo, "pb");
		}
		else
		{
			shortest_rotation_a_pivot(abo, pivot);
		}
	}
	deb_("...end pass pivot.\ncount, complexity:");
	deb_int_(count_instructions_in_str(*abo.o));
	deb_int_(path_complexity(*abo.b));
	NL
	return (1);
}

int				combo_rewind(t_abo abo)
{
	char	*o;

	deb_("\nCombo Rewind!\n");
	while (stack_size(*abo.b) > 0)
	{
		o = best_rewind(abo);
		deb_("Best: '");
		deb_(o);
		deb_("'\n");
		re_ouch(abo, o);
		free(o);
	}
	flush_a(abo);
	deb_("\nFinal:\n\n");
	deb_stack_double_log(*abo.a, *abo.b);
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

void	moderate_shortest_rotation_b_receive(t_abo abo)
{
	int	c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return ;
	deb_("moderate_shortest_rotation_b_receive\n");
	c = calc_top_b(abo, b_before_a(abo));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h, *abo.o), "ra"))
			exec(abo, "rb");
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h, *abo.o), "rra"))
			exec(abo, "rrb");
	}
	return ;
}

int		any_in_range(t_stk *s, int min, int max)
{
	t_stk	*h;

	h = s;
	while (h)
	{
		if (h->val >= min && h->val <= max)
			return (1);
		h = h->nx;
	}
	return (0);
}

int		is_in_range(int x, int min, int max)
{
	if (min == max && x == min)
		return (1);
	if (x >= min && x <= max)
		return (1);
	return (0);
}

int	double_partition(t_abo abo, int pivot[4])
{
	while (any_in_range(*abo.a, pivot[0], pivot[3]))
	{
		deb_quad_pivot(pivot);
		if (is_in_range((*abo.a)->val, pivot[0], pivot[3]))
		{
			if (is_in_range((*abo.a)->val, pivot[0], pivot[1]))
			{
				exec(abo, "pb");
				if (flush_final(abo))
					return (1);
				else
					exec(abo, "rb");
				continue ;
			}
			if (is_in_range((*abo.a)->val, pivot[2], pivot[3]))
			{
				exec(abo, "pb");
			}
		}
		else
			shortest_rotation_a_pivot(abo, pivot[3]);
	}
	return (1);
}

int	any_in_quad_pivot(t_abo abo, int pivot[4])
{
	t_stk	*h;

	h = *abo.a;
	while (h)
	{
		if (h->val >= pivot[0] && h->val <= pivot[1])
			return (1);
		if (h->val >= pivot[2] && h->val <= pivot[3])
			return (1);
		h = h->nx;
	}
	return (0);
}

char	*prev_command(char **h, char *limit)
{
	char	*c;

	c = *h;
	if (c <= limit + 2)
		return (*h);
	if (*(c - 1) == ',')
		c -= 2;
	while (*c != ',' && c > limit)
		c--;
	if (c > limit)
		c++;
	*h = c;
	return (*h);
}

int		slices_by_size(int sz)
{
	if (sz <= 5)
		return (1);
	if (sz <= 20)
		return (2);
	if (sz <= 100)
		return (5);
	if (sz <= 250)
		return (5);
	if (sz <= 500)
		return (7);
	return (sz / 2);
}

void	deb_abo(t_abo abo)
{
	deb_stack_double_log(*abo.a, *abo.b);
	return ;
}

int	quad_partition(t_abo abo, int pivot[4])
{
	static int		c = 0;

	deb_("quad_partition.\n");
	flush_b(abo);
	while (any_in_quad_pivot(abo, pivot) && stack_size(*abo.a) > 2)
	{
		deb_("---\n");
		deb_quad_pivot(pivot);
//		shortest_rot_a_quad(abo, pivot);
		full_rot_a_quad(abo, pivot);
//		if (!(shortest_rot_a_quad(abo, pivot)))
//			return (c);
//		moderate_shortest_rotation_b_receive(abo);
		deb_("...");
		exec(abo, "pb");
		spot(abo, "pb");
		if (c % 2 == 0)
			super_bubble(abo);
		c++;
	}
	return (c);
}

int		auto_slice(t_abo abo)
{
	static int	s = -1;

	s = stack_size(*abo.a) / 10 - 3;
	if (s < 2)
		s = 2;
	deb_("Slices:");
	deb_int_(s);
	NL
	return (s);
	(void)abo;
}

int		soft_slice(t_abo abo)
{
	(void)abo;
	if (stack_size(*abo.a) <= 5)
		return (1);
	return (2);
//	return (stack_size(*abo.a) / 4);
}

int	master_rewind(t_abo abo)
{
	int	c;

	deb_("Master Rewind\n");
	c = 0;
	while (stack_size(*abo.b))
	{
//		if (++c % 4 == 0)
//			bubble(abo);
//		opportunistic_flush_b(abo);
//		flush_b(abo);
//		shortest_a_btoa(abo);
		if (shortest_b_btoa(abo))
			spot(abo, "pa");
		else
			shortest_a_btoa(abo);
//		while (shortest_a_btoa(abo))
//			spot(abo, "pa");
	}
	flush_a(abo);
	deb_("\nFinal:\n\n");
	deb_stack_double_log(*abo.a, *abo.b);
	return (estas_finita(*abo.a, *abo.b));
}

int	simple_partition(t_abo abo, int pivot[4])
{
	while (any_in_quad_pivot(abo, pivot) && stack_size(*abo.a) > 2)
	{
//		full_rot_a_quad(abo, pivot);
		shortest_rot_a_quad(abo, pivot);
		if (stack_size(*abo.a) > stack_size(*abo.b))
			shortest_rotation_b_receive(abo);
		else
			moderate_shortest_rotation_b_receive(abo);
		exec(abo, "pb");
	}
	return (1);
}

int		push_swap_sort(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;
	int		pivot[4];

	pivot[0] = 0;
	pivot[1] = 0;
	pivot[2] = 0;
	pivot[3] = 0;
	abo = make_abo(a, b, o);
	gen_pivot_soft_quad_sand(*a, pivot, soft_slice(abo));
//	gen_pivot_quad_sandwich(*a, pivot, soft_slice(abo));
//	deb_quad_pivot(pivot);
//	gen_pivot_quad_outside_in(*a, pivot, auto_slice(abo));
//	deb_quad_pivot(pivot);
//	gen_pivot_quad_ref(*a, pivot, soft_slice(abo));
	deb_quad_pivot(pivot);
	if (flush_final(abo))
		return (1);
	while (1)
	{
		if (bubble(abo) && flush_final(abo))
			break ;
		else
			if (flush_final(abo))
				break ;
		simple_partition(abo, pivot);
//		quad_partition(abo, pivot);
		if (stack_size(*abo.a) > 2)
			return (push_swap_sort(a, b, o));
		else
			return (master_rewind(abo));
	}
	return (1);
}
