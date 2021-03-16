/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 14:33:04 by fde-capu         ###   ########.fr       */

/* ************************************************************************** */

#include "push_swap.h"

int				ps_try_bubble(t_stk **a, t_stk **b, char **o)
{
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val) && (*b) \
		&& ((*b)->nx) && ((*b)->val < (*b)->nx->val))
			ouch(a, b, o, "ss");
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val))
			ouch(a, b, o, "sa");
	if ((*b) && ((*b)->nx) \
		&& ((*b)->val < (*b)->nx->val))
			ouch(a, b, o, "sb");
	return (estas_finita((*a), (*b)));
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

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	char	*combo_str[4];
	int		combo_stp[4];
	t_stk	*combo_stk_a[4];
	t_stk	*combo_stk_b[4];
	int		best;

	combo_stk_a[0] = stack_clone(*a);
	combo_stk_a[1] = stack_clone(*a);
	combo_stk_a[2] = stack_clone(*a);
	combo_stk_a[3] = stack_clone(*a);
	combo_stk_b[0] = stack_clone(*b);
	combo_stk_b[1] = stack_clone(*b);
	combo_stk_b[2] = stack_clone(*b);
	combo_stk_b[3] = stack_clone(*b);
	combo_str[0] = ft_str("");
	combo_str[1] = ft_str("");
	combo_str[2] = ft_str("");
	combo_str[3] = ft_str("");
	combo_stp[0] = comb_rr(&combo_stk_a[0], &combo_stk_b[0], &combo_str[0]);
	combo_stp[1] = comb_rrr(&combo_stk_a[1], &combo_stk_b[1], &combo_str[1]);
	combo_stp[2] = comb_ra_rrb(&combo_stk_a[2], &combo_stk_b[2], &combo_str[2]);
	combo_stp[3] = comb_rra_rb(&combo_stk_a[3], &combo_stk_b[3], &combo_str[3]);
	best = min_int_idx_arr4(combo_stp);
	re_ouch(a, b, o, combo_str[best]);
	free(combo_str[0]);
	free(combo_str[1]);
	free(combo_str[2]);
	free(combo_str[3]);
	while (stack_size(*b) > 0)
		ouch(a, b, o, "pa");
	return (1);
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
		return (ps_combo_rewind(a, b, o));
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
int deb = 1;
	t_stk	*pivot;
	t_stk	*h;

	while (stack_size(*a) > 1)
	{
		if (ps_try_bubble(a, b, o))
			return (1);
		pivot = stack_tail(*a);
		deb_pivot(pivot);
		h = *a;
		while (1)
		{
if (deb++ > 15) { printf("DEBY!\n"); exit (0); }
			if (ps_try_bubble(a, b, o))
				return (1);
			if (ps_flush_ready(a, b, o))
				return (1);
			if (h->val <= pivot->val)
				ouch(a, b, o, "pb");
			//if ((stack_size(*a) > 1) && (count_le(*a, pivot->val) > 1))
			if (count_le(*a, pivot->val) > 1)
				ouch(a, b, o, "ra");
			else
			{
				ouch(a, b, o, "rra");
				break ;
			}
			h = *a;
			if (h == pivot)
				break ;
		}
	}
	while (stack_size(*b) > 0)
		ouch(a, b, o, "pa");
	return (1);
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	ps_quick_sort(a, b, o);
	return ;
}
