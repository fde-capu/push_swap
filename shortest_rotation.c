/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/08 17:13:24 by fde-capu         ###   ########.fr       */
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

void	deb_op_(t_abo abo, char *x)
{
	if (!DEBUG)
		return ;
	*abo.o = ft_strcatxl(*abo.o, x);
	return ;
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
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

int	shortest_a_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;
	static	int	tol = -1;

	deb_("shortest_a_btoa\n");
	if (tol == -1)
		tol = stack_size(*abo.b) / 10;
	if (tol <= 0)
		tol = 1;
	n = count_natural_a_receive(abo);
	r = count_reverse_a_receive(abo);
	l = count_lasts_rb(abo);
	op = rot_solve(n, r, l);
	if (op < 0 && op * -1 > tol)
	{
		tol++;
		return (0);
	}
//		op = tol * -1;
	if (op > 0 && op > tol)
	{
		tol++;
		return (0);
	}
//		op = tol;
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
	tol = -1;
	return (1);
}

int	shortest_rot_a_quad(t_abo abo, int pivot[4])
{
	int		ra;
	int		rra;
	t_stk	*tgt;
	static int	tol = -1;
	static int	eas = 0;

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
	eas++;
	if (eas % 5 == 0)
		tol--;
	return (1);
}
