/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:24:22 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 16:25:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			deb_pivot(int val)
{
	if (!DEBUG)
		return ;
	ft_print_stdout("New pivot: ");
	ft_print_int(val);
	ft_print_stdout(".\n");
	return ;
}

void		gen_pivot_last(t_stk **a, int *pivot)
{
	*pivot = stack_tail(*a)->val;
	return ;
}

void		gen_pivot_median(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_median(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}

void		gen_pivot_short(t_stk **a, int *pivot)
{
	int	tmp;

	tmp = stack_short(*a)->val;
	if (tmp == *pivot)
		return (gen_pivot_last(a, pivot));
	*pivot = tmp;
	deb_pivot(*pivot);
	return ;
}
