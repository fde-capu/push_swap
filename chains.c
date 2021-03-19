/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/19 13:44:20 by fde-capu         ###   ########.fr       */
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
		deb_("case 1. ");
		return (0);
	}
	if (dir == ASCE && higher == bot && lower == top)
	{
		deb_("case 2. ");
		return (0);
	}
	if (lower > higher)
		return (1);
	deb_("case 3. ");
	return (0);
}

int				bubble_if_ss(t_stk **a, t_stk **b, char **o)
{
	int		oa;
	int		ob;

	deb_("Bubble ss. ");
	oa = may_bubble(*a, ASCE);
	ob = may_bubble(*b, DESC);
	if (oa && ob)
		return (ouch(a, b, o, "ss"));
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

int				comb_rr(t_stk **a, t_stk **b, char **comb)
{
	int	steps;

	steps = 0;
	while(!in_order(*a) || !in_reverse(*b))
	{
		if (!in_order(*a) && !in_reverse(*b))
		{
			ouch(a, b, comb, "rr");
			steps++;
			continue ;
		}
		if (!in_order(*a))
		{
			ouch(a, b, comb, "ra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			ouch(a, b, comb, "rb");
			steps++;
			continue ;
		}
	}
	return (steps);
}

int				comb_rrr(t_stk **a, t_stk **b, char **comb)
{
	int	steps;

	steps = 0;
	while(!in_order(*a) || !in_reverse(*b))
	{
		if (!in_order(*a) && !in_reverse(*b))
		{
			ouch(a, b, comb, "rrr");
			steps++;
			continue ;
		}
		if (!in_order(*a))
		{
			ouch(a, b, comb, "rra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			ouch(a, b, comb, "rrb");
			steps++;
			continue ;
		}
	}
	return (steps);
}

int				comb_ra_rrb(t_stk **a, t_stk **b, char **comb)
{
	int	steps;

	steps = 0;
	while(!in_order(*a) || !in_reverse(*b))
	{
		if (!in_order(*a))
		{
			ouch(a, b, comb, "ra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			ouch(a, b, comb, "rrb");
			steps++;
			continue ;
		}
	}
	return (steps);
}

int				comb_rra_rb(t_stk **a, t_stk **b, char **comb)
{
	int	steps;

	steps = 0;
	while(!in_order(*a) || !in_reverse(*b))
	{
		if (!in_order(*a))
		{
			ouch(a, b, comb, "rra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			ouch(a, b, comb, "rb");
			steps++;
			continue ;
		}
	}
	return (steps);
}

int				min_int_idx_arr4(int combo_stp[])
{
	int	best;
	int	min;

	min = combo_stp[0];
	best = 0;
	if (combo_stp[1] < min)
	{
		min = combo_stp[1];
		best = 1;
	}
	if (combo_stp[2] < min)
	{
		best = 2;
		min = combo_stp[2];
	}
	if (combo_stp[3] < min)
	{
		best = 3;
		min = combo_stp[3];
	}
	return (best);
}

t_stk			*this_is_after(t_stk *a, t_stk *b)
{
	t_stk	*h;
	t_stk	*after;
	int		once;

	deb_("What should succed");
	deb_int_(a->val);
	deb_("? >");
	if (stack_size(b) <= 1)
		return (b);
	after = 0;
	once = 1;
	h = b;
	while (h)
	{
		if (h->val < a->val)
		{
			if (once)
			{
				after = h;
				once = 0;
			}
			if (h->val > after->val)
			{
				after = h;
			}
		}
		h = h->nx;
	}
	if (!after)
		after = max_cell(b);
	deb_int_(after->val);
	deb_("\n");
	return (after);
}

t_stk			*this_is_before(t_stk *a, t_stk *b)
{
	t_stk	*h;
	t_stk	*before;
	int		once;

	deb_("What should preceed");
	deb_int_(b->val);
	deb_("? <");
	if (stack_size(a) <= 1)
		return (a);
	once = 1;
	h = a;
	while (h)
	{
		if (h->val > b->val)
		{
			if (once)
			{
				before = h;
				once = 0;
			}
			if (h->val < before->val)
			{
				before = h;
			}
		}
		h = h->nx;
	}
	deb_int_(before->val);
	deb_("\n");
	return (before);
}

int				position_top(t_stk *a, t_stk *h)
{
	if (!h)
		return (-1);
	return (position_top(a, h->pv) + 1);
}

int				position_bot(t_stk *a, t_stk *h)
{
	if (!h)
		return (0);
	return (position_bot(a, h->nx) + 1);
}

void	put_cell_on_top_a(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*a, cell);
	dist_bot = position_bot(*a, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			ouch(a, b, o, "ra");
	}
	else
	{
		while (dist_bot--)
			ouch(a, b, o, "rra");
	}
	return ;
}

void	put_cell_on_top_b(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*b, cell);
	dist_bot = position_bot(*b, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			ouch(a, b, o, "rb");
	}
	else
	{
		while (dist_bot--)
			ouch(a, b, o, "rrb");
	}
	return ;
}

void			shortest_rotation_prepare(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, max_cell(*b));
	return ;
}

void			shortest_rotation_finish(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_a(a, b, o, min_cell(*a));
	return ;
}

void			shortest_rotation_rewind(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_a(a, b, o, this_is_before(*a, *b));
	return ;
}

void			shortest_rotation_receive(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, this_is_after(*a, *b));
	return ;
}

int			shortest_rotation_forward(t_stk **a, t_stk **b, char **o, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;

	if ((*a)->val <= pivot)
		return (0);
	dist_dn = 0;
	h = *a;
	while (h && h->val > pivot && dist_dn++)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*a);
	while (h && h->val > pivot && dist_up++)
		h = h->pv;
	if (dist_dn < dist_up)
	{
		while (dist_dn--)
			ouch(a, b, o, "ra");
	}
	else
	{
		while (dist_up--)
			ouch(a, b, o, "rra");
	}
	return (1);
}

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	deb_("Combo Rewind!\n");
	shortest_rotation_prepare(a, b, o);
	while (stack_size(*b) > 0)
	{
		//ps_try_bubble(a, b, o);
		shortest_rotation_rewind(a, b, o);
		ouch(a, b, o, "pa");
	}
	shortest_rotation_finish(a, b, o);
	return (estas_finita(*a, *b));
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	deb_("Flush_ready? ");
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
		return (ps_combo_rewind(a, b, o));
	deb_("No.\n");
	return (0);
}

void			deb_stack_double_log(t_stk *a, t_stk *b)
{
	if (DEBUG)
		stack_double_log(a, b);
	return ;
}

void			deb_pivot(int val)
{
	if (!DEBUG)
		return ;
	ft_print_stdout("New pivot: ");
	ft_print_int(val);
	ft_print_stdout(".\n");
	return ;
}

int	ss_bubble_and_flush(t_stk **a, t_stk **b, char **o)
{
	bubble_if_ss(a, b, o);
	return (ps_flush_ready(a, b, o));
}

int	bubble_and_flush(t_stk **a, t_stk **b, char **o)
{
	ps_try_bubble(a, b, o);
	return (ps_flush_ready(a, b, o));
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
			shortest_rotation_receive(a, b, o);
			did = ouch(a, b, o, "pb");
		}
		else
		{
			did = shortest_rotation_forward(a, b, o, pivot);
		}
//		if (bubble_and_flush(a, b, o))
		if (ps_flush_ready(a, b, o))
			return (did);
		h = *a;
	}
	deb_bol_(did);
	return (did);
}

void		gen_pivot_last(t_stk **a, int *pivot)
{
	*pivot = stack_tail(*a)->val;
	return ;
}

void		gen_pivot_median(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_median(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}

void		gen_pivot_short(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_short(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}

int				ps_quick_sort(t_stk **a, t_stk **b, char **o)
{
	int		pivot;

//		gen_pivot_median(a, &pivot);
//		gen_pivot_last(a, &pivot);
	pivot = 0;
	while (1)
	{
		gen_pivot_short(a, &pivot);
		if (stack_size(*a) < 5 && bubble_and_flush(a, b, o))
			break ;
		if (ps_flush_ready(a, b, o))
			break ;
		if (ps_pb_le_pivot(a, b, o, pivot))
			continue ;
		if (ps_combo_rewind(a, b, o))
			break ;
		break ;
	}
	//		new_pivot = 1;
	if (estas_finita(*a, *b))
		return (1);
	return (0);
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	ps_quick_sort(a, b, o);
	return ;
}

t_stk	*stack_median(t_stk *s)
{
	t_stk	*h;
	int		le;
	int		gt;
	int		test;
	int		best;
	t_stk	*median;

	best = INT_MAX;
	h = s;
	while (h)
	{
		le = count_le(s, h->val);
		gt = count_gt(s, h->val);
		test = le - gt - 1;
		if (test < 0)
			test *= -1;
		if (test < best)
		{
			median = h;
			best = test;
		}
		h = h->nx;
	}
	return (median);
}

t_stk	*filter_le(t_stk *s, int control)
{
	t_stk	*xa;
	t_stk	*xb;

	xa = stack_clone(s);
	xb = init_stack_empty();
	while (count_gt(xa, control))
	{
		if (xa->val > control)
			op_run_str("pb", &xa, &xb);
		else
			op_run_str("ra", &xa, &xb);
	}
	destroy_stack(xb);
	return (xa);
}

t_stk	*stack_short(t_stk *s)
{
	t_stk	*tmp;
	int		tiny;

	tmp = filter_le(s, stack_median(s)->val);
	tiny = stack_median(tmp)->val;
	destroy_stack(tmp);
	return (cell_by_val(s, tiny));
}
