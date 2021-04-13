/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:09:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:32:56 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		calc_top_b(t_abo abo, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;
	int		o;

	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.b, cell);
	dist_bot = position_bot(*abo.b, cell);
	if (dist_top < dist_bot)
		o = dist_top;
	else
		o = dist_bot * -1;
	return (o);
}

int		calc_top_a(t_abo abo, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.a, cell);
	dist_bot = position_bot(*abo.a, cell);
	if (dist_top < dist_bot)
		return (dist_top);
	else
		return (dist_bot * -1);
}

int		is_in_quad(int x, int pivot[4])
{
	if (is_in_range(x, pivot[0], pivot[1]))
	{
		deb_("+");
		return (1);
	}
	if (is_in_range(x, pivot[2], pivot[3]))
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
