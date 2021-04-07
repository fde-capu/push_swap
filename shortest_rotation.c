/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/07 09:15:06 by fde-capu         ###   ########.fr       */
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
	if (!abo.b || !*abo.b)
		return ;
	top_b(abo, b_before_a(abo));
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

int		shortest_rotation_a_pivot(t_abo abo, int pivot)
{
	int	n;
	int	r;
	int	l;
	int	op;

	n = count_natural_rotation_a_pivot(abo, pivot);
	r = count_reverse_rotation_a_pivot(abo, pivot);
	l = count_lasts_rb(abo);
	deb_("\nshortest_a_pivot");
	deb_int_(pivot);
	NL
	deb_(*abo.o);
	deb_("\nnatural, reverse, lasts_rb:");
	deb_int_(n);
	deb_int_(r);
	deb_int_(l);
	NL
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

int	spot_up(t_abo abo)
{
	t_stk	*c;

	deb_("spot_up (a to b)? ");
	c = b_before_a(abo);
	if (c == *abo.a || c == *abo.b)
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
	if (c == *abo.b)
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

	c = 0;
	if (ft_stridentical(op, "pb"))
	{
		while (spot_up(abo))
		{
			exec(abo, op);
			c++;
		}
	}
	return (c);
}

int	shortest_rot_a_quad(t_abo abo, int pivot[4])
{
	t_stk	*h;
	int		ra;
	int		rra;

	ra = 0;
	rra = 1;
	h = *abo.a;
	while (h && !(is_in_range(h->val, pivot[0], pivot [1])) && !(is_in_range(h->val, pivot[2], pivot[3])))
	{
		ra++;
		h = h->nx;
	}
	h = stack_tail(*abo.a);
	while (h && !(is_in_range(h->val, pivot[0], pivot [1])) && !(is_in_range(h->val, pivot[2], pivot[3])))
	{
		rra++;
		h = h->pv;
	}
	if (ra <= rra)
	{
		while (ra-- > 0)
		{
			ra -= spot(abo, "pb");
			exec(abo, "ra");
		}
	}
	else
	{
		while (rra-- > 0)
		{
			ra -= spot(abo, "pb") * 0;
			exec(abo, "rra");
		}
	}
	return (1);
}
