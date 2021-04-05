/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/04 22:30:25 by fde-capu         ###   ########.fr       */
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

char	*prev_command(char **h, char *limit)
{
	char	*c;

	c = *h;
	if (*(c - 1) == ',')
		c -= 2;
	while (*c != ',' && c > limit)
		c--;
	if (c > limit)
		c++;
	*h = c;
	return (*h);
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
	if (perfect_spot(abo))
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
	s_1_(loc[0]);
	s_2_(loc[1]);
	treat_loc_redundancies(loc);
	count_loc_instructions(c, loc);
	return (clear_ret(loc, lower_c_loc_o(c, loc)));
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

void	easy_put(t_abo abo)
{
	int		pivot;
	t_stk	*h;

	pivot = 0;
	while (stack_size(*abo.a) > 2)
	{
		pivot = (*abo.a)->val;
//		gen_pivot_slice(*abo.a, &pivot, 4);
		while (count_le(*abo.a, pivot))
		{
			h = *abo.a;
			if (h->val <= pivot)
			{
				moderate_shortest_rotation_b_receive(abo);
				bubble(abo);
				exec(abo, "pb");
			}
			else
			{
				exec(abo, "ra");
			}
		}
	}
	return ;
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

int	partition(t_abo abo, int pivot)
{
	int		did;
	t_stk	*h;

	did = 0;
	h = *abo.a;
	while (h && h->nx)
	{
		deb_("Try pass pivot for");
		deb_int_(h->val);
		deb_(", pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			moderate_shortest_rotation_b_receive(abo);
			exec(abo, "pb");
			if (count_le(h, pivot))
				bubble(abo);
			else
				break ;
			did++;
		}
		else
		{
			if (!(count_le(h, pivot)))
				break ;
			shortest_rotation_a_pivot(abo, pivot);
		}
		h = *abo.a;
	}
	flush_b(abo);
	deb_("...end pass pivot.\ncount, complexity:");
	deb_int_(count_instructions_in_str(*abo.o));
	deb_int_(path_complexity(*abo.b));
	NL
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
	t_abo	abo;

	abo = make_abo(a, b, o);
	easy_put(abo);
//	easy_get(abo);
	combo_rewind(abo);
	return (1);
}

void		trash(void)
{
//	if (flush_final(abo))
//		return (1);
//	while (1)
//	{
//		if (bubble(abo) && flush_final(abo))
//			break ;
//		if (flush_final(abo))
//			break ;
//		easy_put(abo, pivot);
//		if (stack_size(*abo.a) > 2)
//			return (push_swap_sort(a, b, o));
//		else
//			return (combo_rewind(abo));
//	}
//	return (1);
	return ;
}
