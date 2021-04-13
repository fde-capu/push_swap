/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:44:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:12:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_it_to_stdout(t_ttg *s)
{
	char	*h;

	if (DEBUG)
	{
		deb_int_(s->result);
		return ;
	}
	if (!(s->formula))
		return ;
	h = s->formula;
	while (*h)
	{
		if (*h == ',')
			write(1, "\n", 1);
		else
			write(1, h, 1);
		h++;
	}
	if (h != s->formula)
		write(1, "\n", 1);
	return ;
}

t_abo		make_abo(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;

	abo.a = a;
	abo.b = b;
	abo.o = o;
	return (abo);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
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

int		is_in_range(int x, int min, int max)
{
	if (min == max && x == min)
		return (1);
	if (x >= min && x <= max)
		return (1);
	return (0);
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

int				any_in_quad_pivot(t_abo abo, int pivot[4])
{
	t_stk	*h;

	h = *abo.a;
	while (h)
	{
		if (h->val >= pivot[0] && h->val <= pivot[1])
			return (1);
		if (h->val >= pivot[2] && h->val <= pivot[3])
			return (1);
		h = h->nx;
	}
	return (0);
}

int				piv_higher(t_stk *cell, int pivot[4])
{
	if (!cell)
		return (1);
	deb_int_(cell->val);
	deb_(":");
	deb_quad_pivot(pivot);
	deb_("HIGH? ");
	if (cell && is_in_range(cell->val, pivot[2], pivot[3]))
		return (deb_bol_(1));
	return (deb_bol_(0));
}

int				piv_lower(t_stk *cell, int pivot[4])
{
	if (!cell)
		return (1);
	deb_int_(cell->val);
	deb_(":");
	deb_quad_pivot(pivot);
	deb_("LOW? ");
	if (cell && is_in_range(cell->val, pivot[0], pivot[1]))
		return (deb_bol_(1));
	return (deb_bol_(0));
}

