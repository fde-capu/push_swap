/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/17 18:12:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ps_try_bubble(t_stk **a, t_stk **b, char **o, t_stk **h)
{
	if (DEBUG)
		ft_print_stdout("try bubble\n");
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val) && (*b) \
		&& ((*b)->nx) && ((*b)->val < (*b)->nx->val))
	{
		if (in_reverse_out_of_rot(*b))
		{
			if (*a != max_cell(*a))
			{
				ouch(a, b, o, "sa");
				*h = (*h)->pv;
			}
		}
		else
		{
			ouch(a, b, o, "ss");
			*h = (*h)->pv;
		}
		return (ps_flush_ready(a, b, o));
	}
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val))
	{
		if (*a != max_cell(*a))
		{
			ouch(a, b, o, "sa");
			*h = (*h)->pv;
		}
	}
	if ((*b) && ((*b)->nx) \
		&& ((*b)->val < (*b)->nx->val))
			ouch(a, b, o, "sb");
	return (ps_flush_ready(a, b, o));
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

t_stk			*this_is_before(t_stk *a, t_stk *b)
{
	t_stk	*h;
	t_stk	*before;
	int		once;

	if (DEBUG)
	{
		ft_print_stdout("What should preceed ");
		ft_print_int(b->val);
		ft_print_stdout("? > ");
	}
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
	if (DEBUG)
	{
		ft_print_int(before->val);
		ft_print_stdout("\n");
	}
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

void			shortest_rotation_finish(t_stk **a, char **o)
{
	t_stk	*before;
	int		dist_top;
	int		dist_bot;

	before = min_cell(*a);
	dist_top = position_top(*a, before);
	dist_bot = position_bot(*a, before);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			ouch(a, a, o, "ra");
	}
	else
	{
		while (dist_bot--)
			ouch(a, a, o, "rra");
	}
	return ;
}

void			shortest_rotation_rewind(t_stk **a, t_stk **b, char **o)
{
	t_stk	*before;
	int		dist_top;
	int		dist_bot;

	before = this_is_before(*a, *b);
	dist_top = position_top(*a, before);
	dist_bot = position_bot(*a, before);
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

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
//	char	*combo_str[4];
//	int		combo_stp[4];
//	t_stk	*combo_stk_a[4];
//	t_stk	*combo_stk_b[4];
//	int		best;

	if (DEBUG)
		ft_print_stdout("Combo Rewind!\n");
//	combo_stk_a[0] = stack_clone(*a);
//	combo_stk_a[1] = stack_clone(*a);
//	combo_stk_a[2] = stack_clone(*a);
//	combo_stk_a[3] = stack_clone(*a);
//	combo_stk_b[0] = stack_clone(*b);
//	combo_stk_b[1] = stack_clone(*b);
//	combo_stk_b[2] = stack_clone(*b);
//	combo_stk_b[3] = stack_clone(*b);
//	combo_str[0] = ft_str("");
//	combo_str[1] = ft_str("");
//	combo_str[2] = ft_str("");
//	combo_str[3] = ft_str("");
//	combo_stp[0] = comb_rr(&combo_stk_a[0], &combo_stk_b[0], &combo_str[0]);
//	combo_stp[1] = comb_rrr(&combo_stk_a[1], &combo_stk_b[1], &combo_str[1]);
//	combo_stp[2] = comb_ra_rrb(&combo_stk_a[2], &combo_stk_b[2], &combo_str[2]);
//	combo_stp[3] = comb_rra_rb(&combo_stk_a[3], &combo_stk_b[3], &combo_str[3]);
//	best = min_int_idx_arr4(combo_stp);
//	re_ouch(a, b, o, combo_str[best]);
//	free(combo_str[0]);
//	free(combo_str[1]);
//	free(combo_str[2]);
//	free(combo_str[3]);
	while (stack_size(*b) > 0)
	{
		shortest_rotation_rewind(a, b, o);
		ouch(a, b, o, "pa");
	}
	shortest_rotation_finish(a, o);
	return (1);
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	if (DEBUG)
		ft_print_stdout("Flush_ready? ");
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
		return (ps_combo_rewind(a, b, o));
	if (DEBUG)
		ft_print_stdout("No.\n");
	return (0);
}

void			deb_stack_double_log(t_stk *a, t_stk *b)
{
	if (DEBUG)
		stack_double_log(a, b);
	return ;
}

void			deb_pivot(t_stk *p)
{
	char	*str;

	if (!DEBUG)
		return ;
	ft_print_stdout("New pivot: ");
	str = ft_itoa(p->val);
	ft_print_stdout(str);
	free(str);
	ft_print_stdout(".\n");
	return ;
}

int				ps_quick_sort(t_stk **a, t_stk **b, char **o)
{
//int deb = 1;
	t_stk	*pivot;
	t_stk	*h;

	while (!estas_finita(*a, *b))
	{
		while (stack_size(*a) > 1)
		{
			pivot = stack_median(*a);
			deb_pivot(pivot);
			h = *a;
//			while (1)
//			{
				if (ps_try_bubble(a, b, o, &h))
					return (1) ;
				//if (deb++ > 15) { printf("DEBY!\n"); exit (0); }
				while (h->val <= pivot->val)
				{
					ouch(a, b, o, "pb");
					h = *a;
//					if (h == pivot)
//						break ;
					if (ps_try_bubble(a, b, o, &h))
						return (1);
				}
				if (count_le(*a, pivot->val) > 1)
				{
					ouch(a, b, o, "ra");
					if (ps_try_bubble(a, b, o, &h))
						return (1);
				}
				else
				{
					if (stack_size(*a) > 1)
					{
						ouch(a, b, o, "rra");
						if (ps_try_bubble(a, b, o, &h))
							return (1);
						break ;
					}
				}
				h = *a;
//				if (h == pivot)
//					break ;
//			}
		}
//		while (stack_size(*b) > 0)
//		{
//			shortest_rotation_rewind(a, b, o);
//			ouch(a, b, o, "pa");
//		}
//		shortest_rotation_finish(a, o);
	}
	return (1);
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

