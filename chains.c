/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 13:17:20 by fde-capu         ###   ########.fr       */

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
	while(!in_order(*a) && !in_reverse(*b))
	{
		if (!in_order(*a) && !in_reverse(*b))
		{
			pre_ouch(a, b, comb, "rr");
			steps++;
			continue ;
		}
		if (!in_order(*a))
		{
			pre_ouch(a, b, comb, "ra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			pre_ouch(a, b, comb, "rb");
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
	while(!in_order(*a) && !in_reverse(*b))
	{
		if (!in_order(*a) && !in_reverse(*b))
		{
			pre_ouch(a, b, comb, "rrr");
			steps++;
			continue ;
		}
		if (!in_order(*a))
		{
			pre_ouch(a, b, comb, "rra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			pre_ouch(a, b, comb, "rrb");
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
	while(!in_order(*a) && !in_reverse(*b))
	{
		if (!in_order(*a))
		{
			pre_ouch(a, b, comb, "ra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			pre_ouch(a, b, comb, "rrb");
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
	while(!in_order(*a) && !in_reverse(*b))
	{
		if (!in_order(*a))
		{
			pre_ouch(a, b, comb, "rra");
			steps++;
			continue ;
		}
		if (!in_order(*b))
		{
			pre_ouch(a, b, comb, "rb");
			steps++;
			continue ;
		}
	}
	return (steps);
}

int				max_int_idx_arr4(int combo_stp[4])
{
	int	best;
	int	max;

	max = combo_stp[0];
	best = 0;
	if (combo_stp[1] > max)
	{
		max = combo_stp[1];
		best = 1;
	}
	if (combo_stp[2] > max)
	{
		best = 2;
		max = combo_stp[2];
	}
	if (combo_stp[3] > max)
	{
		best = 3;
		max = combo_stp[3];
	}
	return (best);
}

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	char	*combo_str[4];
	int		combo_stp[4];
	int		best;

	printf("combo rewind!\n");
	combo_str[0] = ft_str("");
	combo_str[1] = ft_str("");
	combo_str[2] = ft_str("");
	combo_str[3] = ft_str("");
	combo_stp[0] = comb_rr(a, b, &combo_str[0]);
	combo_stp[1] = comb_rrr(a, b, &combo_str[1]);
	combo_stp[2] = comb_ra_rrb(a, b, &combo_str[2]);
	combo_stp[3] = comb_rra_rb(a, b, &combo_str[3]);
	best = max_int_idx_arr4(combo_stp);
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

int				ps_quick_sort(t_stk **a, t_stk **b, char **o)
{
	int deb = 1;
	t_stk	*pivot;
	t_stk	*h;

	while (stack_size(*a) > 1)
	{
		if (deb++ > 12) { printf("DEBY!\n"); exit (0); }
		if (ps_try_bubble(a, b, o))
			return (1);
		pivot = stack_tail(*a);
		printf("New pivot: %d\n", pivot->val);
		h = *a;
		while (1)
		{
			if (ps_try_bubble(a, b, o))
				return (1);
			if (ps_flush_ready(a, b, o))
				return (1);
			if (h->val <= pivot->val)
				ouch(a, b, o, "pb");
			if ((stack_size(*a) > 1) && (count_le(*a, pivot->val) > 1))
				ouch(a, b, o, "ra");
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
