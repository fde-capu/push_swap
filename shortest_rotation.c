/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/30 16:54:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_b(t_abo abo)
{
	deb_("flush_b. ");
	top_b(abo, max_cell(*abo.b));
	return ;
}

void	flush_a(t_abo abo)
{
	deb_("flush_a. ");
	top_a(abo, min_cell(*abo.a));
	return ;
}

void	shortest_rotation_a_receive(t_abo abo)
{
	if (!abo.b || !*abo.b)
		return ;
	top_a(abo, this_is_before_atob(abo));
	return ;
}

void	shortest_rotation_b_receive(t_abo abo)
{
	top_b(abo, this_is_after_btoa(abo));
	return ;
}

void	shortest_rotation_a_pivot(t_abo abo, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	t_stk	**a;
	t_stk	**b;

	a = abo.a;
	b = abo.b;
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
			exec(abo, "ra");
	}
	else
	{
		while (dist_up--)
			exec(abo, "rra");
	}
	return ;
}
