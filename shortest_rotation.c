/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/27 13:42:13 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shortest_rotation_dir_pivot(t_abo abo, int dir, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	t_stk	**a;
	t_stk	**b;

	if (dir == ATOB)
	{
		a = abo.a;
		b = abo.b;
	}
	if (dir == BTOA) // may fail for inverse positioning b
	{
		a = abo.b;
		b = abo.a;
	}
	if ((*a)->val <= pivot)
		return ;
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
			ouch_abo(abo, dir, "r_");
	}
	else
	{
		while (dist_up--)
			ouch_abo(abo, dir, "rr_");
	}
	return ;
}

void	shortest_rotation_b_flush(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, max_cell(*b));
	return ;
}

void	shortest_rotation_a_flush(t_stk **a, t_stk **b, char **o)
{
	deb_("shortest_rotation_a_flush.\n");
	put_cell_on_top_a(a, b, o, min_cell(*a));
	return ;
}

void	shortest_rotation_a_receive(t_stk **a, t_stk **b, char **o)
{
	if (!b || !*b)
		return ;
	put_cell_on_top_a(a, b, o, this_is_before_atob(*a, *b));
	return ;
}

void	shortest_rotation_b_receive(t_stk **a, t_stk **b, char **o)
{
	put_cell_on_top_b(a, b, o, this_is_after_btoa(*a, *b));
	return ;
}

int		shortest_rotation_a_pivot(t_stk **a, t_stk **b, char **o, int pivot)
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
