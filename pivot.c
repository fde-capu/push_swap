/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/12 17:22:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		gen_pivot_last(t_stk **a, int *pivot)
{
	*pivot = stack_tail(*a)->val;
	return ;
}

void		gen_pivot_short(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_short(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	return ;
}

t_stk	*stack_short(t_stk *s)
{
	t_stk	*tmp;
	t_stk	*tmp2;
	int		tiny;

	tmp = filter_le(s, stack_median(s)->val);
	tmp2 = filter_le(tmp, stack_median(tmp)->val);
	tiny = stack_median(tmp2)->val;
	destroy_stack(tmp);
	destroy_stack(tmp2);
	return (cell_by_val(s, tiny));
}

t_stk	*stack_median(t_stk *s)
{
	t_stk	*h;
	t_stk	*l;
	int		flip;

	flip = 0;
	h = max_cell(s);
	l = min_cell(s);
	while (h != l)
	{
		if (flip)
		{
			h = cell_val_before(s, h);
			flip = 0;
		}
		else
		{
			l = cell_val_after(s, l);
			flip = 1;
		}
	}
	return (l);
}

t_stk	*filter_le(t_stk *s, int control)
{
	t_stk	*xa;
	t_stk	*xb;

	xa = stack_clone(s);
	xb = init_stack_empty();
	while (count_le(xa, control))
	{
		if (xa->val <= control)
			op_run_str("pb", &xa, &xb);
		else
			op_run_str("ra", &xa, &xb);
	}
	destroy_stack(xa);
	return (xb);
}

void	gen_pivot_slice(t_stk *s, int *pivot, int slices)
{
	static int	size = -1;
	t_stk		*h;
	t_stk		*xa;
	t_stk		*xb;

	if (size == -1)
		size = stack_size(s) / slices;
	if (stack_size(s) <= size)
		size = stack_size(s);
	if (size < 3)
	{
		*pivot = stack_median(s)->val;
		return ;
	}
	xa = stack_clone(s);
	xb = init_stack_empty();
	while (stack_size(xb) < size)
	{
		h = min_cell(xa);
		while (xa != h)
			op_run_str("ra", &xa, &xb);
		op_run_str("pb", &xa, &xb);
	}
	h = cell_by_val(s, max_cell(xb)->val);
	destroy_stack(xa);
	destroy_stack(xb);
	*pivot = h->val;
	return ;
}

t_stk	*stack_chop(t_stk *s, int min, int max)
{
	t_stk	*xa;
	t_stk	*xb;

	xa = stack_clone(s);
	xb = init_stack_empty();
	while (any_in_range(xa, min, max))
	{
		while (xa->val < min || xa->val > max)
			op_run_str("ra", &xa, &xb);
		op_run_str("pb", &xa, &xb);
	}
	destroy_stack(xa);
	return (xb);
}

int		val_before(t_stk *s, int med)
{
	int		ctl;
	t_stk	*h;

	ctl = min_val(s);
	h = s;
	while (h)
	{
		if (h->val > ctl && h->val < med)
			ctl = h->val;
		h = h->nx;
	}
	return (ctl);
}

int		val_after(t_stk *s, int med)
{
	int		ctl;
	t_stk	*h;

	ctl = max_val(s);
	h = s;
	while (h)
	{
		if (h->val < ctl && h->val > med)
			ctl = h->val;
		h = h->nx;
	}
	return (ctl);
}

t_stk	*cell_val_after(t_stk *s, t_stk *h)
{
	int	c;

	c = val_after(s, h->val);
	return (cell_by_val(s, c));
}

t_stk	*cell_val_before(t_stk *s, t_stk *h)
{
	int	c;

	c = val_before(s, h->val);
	return (cell_by_val(s, c));
}

void	deb_quad_pivot(int pivot[4])
{
	deb_("pivot:");
	deb_int_(pivot[0]);
	deb_int_(pivot[1]);
	deb_int_(pivot[2]);
	deb_int_(pivot[3]);
	NL
	return ;
}

void	gen_pivot_quad(t_stk *s, int pivot[4], int slices)
{
	t_stk		*chp;
	int			med;

	pivot[1] = 0;
	pivot[2] = 0;
	pivot[3] = 0;
	pivot[0] = min_val(s);
	gen_pivot_slice(s, &pivot[3], slices);
	chp = stack_chop(s, pivot[0], pivot[3]);
	med = 0;
	gen_pivot_median(&chp, &med);
	pivot[2] = med;
	pivot[1] = val_before(s, med);
	destroy_stack(chp);
	return ;
}

int	size_by_slice(t_stk *s, int slices)
{
	static int	size = -1;

	if (size != -1)
		return (size);
	size = stack_size(s) / slices;
	if (size < 6)
		size = 6;
	return (size);
}

int		next_n_vals(t_stk *s, int x, int n)
{
	int	v;

	v = x;
	while (--n > 0)
	{
		v = val_after(s, v);
	}
	return (v);
}

int		prev_n_vals(t_stk *s, int x, int n)
{
	int	v;

	v = x;
	while (--n > 0)
	{
		v = val_before(s, v);
	}
	return (v);
}

int	spot_up(t_abo abo)
{
	t_stk	*c;

	deb_("spot_up (a to b)? ");
	c = b_before_a(abo);
	if (c == *abo.b && stack_size(*abo.b) >= 2)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int				spot_dn(t_abo abo)
{
	t_stk	*c;

	deb_("spot_dn (b to a)? ");
	c = a_after_b(abo);
	if (c == *abo.a && stack_size(*abo.a) >= 2)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int	spot(t_abo abo, char *op)
{
	int	c;

	deb_("Spot!\n");
	c = 0;
	if (ft_stridentical(op, "pb"))
	{
		while (spot_up(abo))
		{
			exec(abo, op);
			c++;
		}
	}
	if (ft_stridentical(op, "pa"))
	{
		while (spot_dn(abo))
		{
			exec(abo, op);
			c++;
		}
	}
	return (c);
}

void		gen_pivot_median(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_median(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	return ;
}

void	gen_pivot_quad_sandwich(t_stk *s, int pivot[4], int slices)
{
	int			mini_size;
	static int	med = -1;

	mini_size = size_by_slice(s, slices) / 2;
	deb_("size:");
	deb_int_(mini_size * 2);
	NL
	if (med == -1)
		gen_pivot_median(&s, &med);
	pivot[1] = val_before(s, med);
	pivot[0] = prev_n_vals(s, pivot[1], mini_size);
	pivot[2] = val_after(s, pivot[1]);
	pivot[3] = next_n_vals(s, pivot[2], mini_size);
	return ;
}

void	gen_pivot_soft_quad_sand(t_stk *s, int pivot[4], int slices)
{
	int			mini_size;
	int			med;

	mini_size = stack_size(s) / slices / 4;
//	mini_size = size_by_slice(s, slices) / 2;
	deb_("size:");
	deb_int_(mini_size * 2);
	NL
	med = -1;
	gen_pivot_median(&s, &med);
	pivot[1] = val_before(s, med);
	pivot[0] = prev_n_vals(s, pivot[1], mini_size);
	pivot[2] = val_after(s, pivot[1]);
	pivot[3] = next_n_vals(s, pivot[2], mini_size);
	return ;
}

void	gen_pivot_quad_outside_in(t_stk *s, int pivot[4], int slices)
{
	int	mini_size;

	mini_size = size_by_slice(s, slices) / 2;
	deb_("size:");
	deb_int_(mini_size * 2);
	NL
	pivot[0] = min_val(s);
	pivot[1] = next_n_vals(s, pivot[0], mini_size);
	pivot[3] = max_val(s);
	pivot[2] = prev_n_vals(s, pivot[3], mini_size);
	return ;
}

void	gen_pivot_quad_ref(t_stk *s, int pivot[4], int slices)
{
	int	mini_size;

//	mini_size = size_by_slice(s, slices);
	mini_size = stack_size(s) / slices;
	deb_("size:");
	deb_int_(mini_size * 2);
	NL
	pivot[2] = s->val;
	pivot[3] = next_n_vals(s, pivot[2], mini_size);
	pivot[1] = val_before(s, pivot[2]);
	pivot[0] = prev_n_vals(s, pivot[1], mini_size);
	return ;
}
