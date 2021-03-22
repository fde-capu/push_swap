/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 17:57:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			shortest_rotation_b_flush(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, max_cell(*b));
	return ;
}

void			shortest_rotation_finish(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_a(a, b, o, min_cell(*a));
	return ;
}

void			shortest_rotation_a_flush(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_a(a, b, o, this_is_before(*a, *b));
	return ;
}

void			shortest_rotation_b_pivot(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, this_is_after(*a, *b));
	return ;
}

int			shortest_rotation_a_pivot(t_stk **a, t_stk **b, char **o, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;

	if ((*a)->val <= pivot)
		return (0);
	dist_dn = 0;
	h = *a;
	while (h && h->val > pivot && dist_dn++)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*a);
	while (h && h->val > pivot && dist_up++)
		h = h->pv;
	if (dist_dn < dist_up)
	{
		while (dist_dn--)
			ouch(a, b, o, "ra");
	}
	else
	{
		while (dist_up--)
			ouch(a, b, o, "rra");
	}
	return (1);
}
