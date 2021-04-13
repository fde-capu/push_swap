/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:07:53 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	gen_pivot_median(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_median(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	return ;
}

int		size_by_slice(t_stk *s, int slices)
{
	static int	size = -1;

	if (size != -1)
		return (size);
	size = stack_size(s) / slices / 2;
	if (size < 10)
		size = 4;
	return (size);
}

void	gen_pivot_soft_quad_sand(t_stk *s, int pivot[4], int slices)
{
	int			mini_size;
	int			med;

	mini_size = size_by_slice(s, slices) / 2;
	deb_("size:");
	deb_int_(mini_size * 2);
	med = -1;
	gen_pivot_median(&s, &med);
	pivot[1] = val_before(s, med);
	pivot[0] = prev_n_vals(s, pivot[1], mini_size);
	pivot[2] = val_after(s, pivot[1]);
	pivot[3] = next_n_vals(s, pivot[2], mini_size);
	return ;
}
