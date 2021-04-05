/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/05 13:27:55 by fde-capu         ###   ########.fr       */
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
	if (!abo.b || !*abo.b)
		return ;
	top_a(abo, a_after_b(abo));
	return ;
}

void	shortest_rotation_b_receive(t_abo abo)
{
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
