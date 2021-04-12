/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/12 17:20:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_b(t_abo abo)
{
	deb_("\nflush_b\n");
	top_b(abo, max_cell(*abo.b));
	return ;
}

void	flush_a(t_abo abo)
{
	top_a(abo, min_cell(*abo.a));
	return ;
}

void	shortest_rotation_a_receive(t_abo abo)
{
	if (!abo.a || !*abo.a || !abo.b || !*abo.b)
		return ;
	top_a(abo, a_after_b(abo));
	return ;
}

void	short_b_receive_or_flush(t_abo abo)
{
	int	max;
	int	rec;

	if (!abo.b || !*abo.b)
		return ;
	max = calc_top_b(abo, max_cell(*abo.b));
	rec = calc_top_b(abo, b_before_a(abo));
	if (max < 0)
		max *= -1;
	if (rec < 0)
		rec *= -1;
	if (rec < max)
		top_b(abo, b_before_a(abo));
	else
		top_b(abo, max_cell(*abo.b));
	return ;
}

void	shortest_rotation_b_receive(t_abo abo)
{
	t_stk	*bba;

	if (!abo.b || !*abo.b)
		return ;
	bba = b_before_a(abo);
	top_b(abo, bba);
	return ;
}

void	shortest_rotation_b_give(t_abo abo)
{
	top_b(abo, b_before_a(abo));
	return ;
}

int		count_reverse_rotation_a_pivot(t_abo abo, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	int		o;

	if ((*abo.a)->val <= pivot)
		return (0);
	dist_dn = 0;
	h = *abo.a;
	while (h && h->val > pivot && ++dist_dn)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*abo.a);
	while (h && h->val > pivot && ++dist_up)
		h = h->pv;
	if (dist_dn >= dist_up)
		o = dist_dn;
	else
		o = dist_up * -1;
	return (o);
}

int		count_natural_rotation_a_pivot(t_abo abo, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	int		o;

	if ((*abo.a)->val <= pivot)
		return (0);
	dist_dn = 0;
	h = *abo.a;
	while (h && h->val > pivot && ++dist_dn)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*abo.a);
	while (h && h->val > pivot && ++dist_up)
		h = h->pv;
	if (dist_dn < dist_up)
		o = dist_dn;
	else
		o = dist_up * -1;
	return (o);
}

int		count_lasts_rb(t_abo abo)
{
	char	*h;
	int		c;

	c = 0;
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rb"))
		c++;
	if (c)
		return (c);
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rrb"))
		c--;
	return (c);
}

int		count_lasts_ra(t_abo abo)
{
	char	*h;
	int		c;

	c = 0;
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "ra"))
		c++;
	if (c)
		return (c);
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rra"))
		c--;
	return (c);
}

char	*last_command(t_abo abo)
{
	char	*h;

	h = *abo.o + ft_strlen(*abo.o);
	prev_command(&h, *abo.o);
	deb_("last_command ");
	deb_(h);
	return (h);
}

int		rot_solve(int n, int r, int l)
{
	int	op;

	op = 0;
	if (r > n)
	{
		op = n;
		n = r;
		r = op;
		op = 0;
	}
	if (l > 0)
	{
		if (n - l < r * -1)
			op = n;
		else
			op = r;
	}
	else
	{
		if (r - l > n * -1)
			op = r;
		else
			op = n;
	}
	return (op);
}

int		count_natural_a_receive(t_abo abo)
{
	return (calc_top_a(abo, a_after_b(abo)));
}

int		count_reverse_a_receive(t_abo abo)
{
	int		dist_top;
	int		dist_bot;
	t_stk	*cell;

	cell = a_after_b(abo);
	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.a, cell);
	dist_bot = position_bot(*abo.a, cell);
	if (dist_top >= dist_bot)
		return (dist_top);
	else
		return (dist_bot);
}

int		shortest_rotation_a_pivot(t_abo abo, int pivot)
{
	int	n;
	int	r;
	int	l;
	int	op;

	n = count_natural_rotation_a_pivot(abo, pivot);
	r = count_reverse_rotation_a_pivot(abo, pivot);
	l = count_lasts_rb(abo);
	op = rot_solve(n, r, l);
	if (op > 0)
	{
		while (op-- > 0)
			exec(abo, "ra");
	}
	else
	{
		while (op++ < 0)
			exec(abo, "rra");
	}
	return (op);
}

t_stk	*natural_walk(t_abo abo, int pivot[4], int *ra, int *rra)
{
	t_stk	*h;
	t_stk	*p;
	t_stk	*t1;
	t_stk	*t2;
	t_stk	*best;

	h = *abo.a;
	t1 = h;
	while (h && !(is_in_range(h->val, pivot[0], pivot [1])) && !(is_in_range(h->val, pivot[2], pivot[3])))
	{
		*ra += 1;
		h = h->nx;
		t1 = h;
	}
	p = stack_tail(*abo.a);
	t2 = p;
	while (p && !(is_in_range(p->val, pivot[0], pivot [1])) && !(is_in_range(p->val, pivot[2], pivot[3])))
	{
		*rra += 1;
		p = p->pv;
		t2 = p;
	}
	if (*ra <= *rra)
		best = t1;
	else
		best = t2;
	return (best);
}

int	is_in_quad(int x, int pivot[4])
{
	if(is_in_range(x, pivot[0], pivot[1]))
	{
		deb_("+");
		return (1);
	}
	if(is_in_range(x, pivot[2], pivot[3]))
	{
		deb_("+");
		return (1);
	}
	return (0);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		opportunistic_b_receive(t_abo abo)
{
	int	c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return (0);
	deb_("opportunistic_b_receive\n");
	c = calc_top_b(abo, b_before_a(abo));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h, *abo.o), "ra"))
		{
			exec(abo, "rb");
			c -= spot(abo, "pb");
		}
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h, *abo.o), "rra"))
		{
			exec(abo, "rrb");
			c -= spot(abo, "pb");
		}
	}
	return (1);
}

int		opportunistic_flush_b(t_abo abo)
{
	int	w;
	char	*op;

	deb_("\nopportunistic_flush_b:");
	w = calc_top_b(abo, max_cell(*abo.b));
	if (w < 0)
	{
		op = ft_str("rrb");
		w *= -1;
	}
	else
		op = ft_str("rb");
	while (w > 0)
	{
		w -= spot(abo, "pa");
		exec(abo, op);
		w--;
	}
	free(op);
	deb_("done!\n");
	return (0);
}

int	count_natural_b_give(t_abo abo)
{
	return (calc_top_b(abo, b_before_a(abo)));
}

int	count_reverse_b_give(t_abo abo)
{
	int		dist_top;
	int		dist_bot;
	t_stk	*cell;

	cell = b_before_a(abo);
	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.b, cell);
	dist_bot = position_bot(*abo.b, cell);
	if (dist_top >= dist_bot)
		return (dist_top);
	else
		return (dist_bot);
}

int	shortest_b_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	deb_("shortest_b_btoa\n");
	if (!abo.b || !*abo.b)
		return (0);
	n = count_natural_b_give(abo);
	r = count_reverse_b_give(abo);
	l = count_lasts_ra(abo);
	op = rot_solve(n, r, l);
	deb_int_(op);
	if (op > 0)
	{
		while (op-- > 0)
		{
			exec(abo, "rb");
			op -= spot(abo, "pa");
		}
	}
	else
	{
		while (op++ < 0)
		{
			exec(abo, "rrb");
			spot(abo, "pa");
		}
	}
	return (spot_dn(abo));
}

int	shortest_a_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	deb_("shortest_a_btoa\n");
	n = count_natural_a_receive(abo);
	r = count_reverse_a_receive(abo);
	l = count_lasts_rb(abo);
	op = rot_solve(n, r, l);
	if (op > 0)
	{
		while (op-- > 0)
		{
			exec(abo, "ra");
			if(spot(abo, "pa"))
				return (0);
		}
		return (1);
	}
	if (op < 0)
	{
		while (op++ < 0)
		{
			exec(abo, "rra");
			if (spot(abo, "pa"))
				return (0);
		}
		return (1);
	}
	return (-1);
}

int	full_rot_a_quad(t_abo abo, int pivot[4])
{
	deb_("full_rot_a_quad\n");
	while (!(is_in_quad((*abo.a)->val, pivot)))
		exec(abo, "ra");
	return (1);
}

int	shortest_rot_a_quad(t_abo abo, int pivot[4])
{
	int		ra;
	int		rra;
	t_stk	*tgt;
	static int	tol = -1;

	if (tol == -1)
		tol = stack_size(*abo.a) / 10;
	ra = 0;
	rra = 1;
	tgt = natural_walk(abo, pivot, &ra, &rra);
	deb_("Track:");
	deb_int_(tgt->val);
	deb_int_(ra);
	deb_int_(rra);
	NL
	if (min(ra, rra) >= tol)
	{
		tol++;
		deb_("Too long.\n");
		return (0);
	}
	if (ra <= rra)
	{
		while (ra > 0 && stack_size(*abo.a) > 2)
		{
			exec(abo, "ra");
			ra--;
		}
	}
	else
	{
		while (rra > 0 && stack_size(*abo.a) > 2)
		{
			exec(abo, "rra");
			rra--;
		}
	}
	return (1);
}

t_stk	*nx(t_stk *h)
{
	h = h->nx;
	if (!h)
		h = stack_head(h);
	return (h);
}

t_stk	*pv(t_stk *h)
{
	h = h->pv;
	if (!h)
		h = stack_tail(h);
	return (h);
}

t_stk	*nx_in_quad_pivot(t_stk *ref, int pivot[4])
{
	t_stk	*h;

	h = nx(ref);
	while (!(is_in_quad(h->val, pivot)))
		h = nx(h);
	return (h);
}
