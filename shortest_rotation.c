/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/01 13:33:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_b(t_abo abo)
{
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
	while (h && h->val > pivot && dist_dn++)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*abo.a);
	while (h && h->val > pivot && dist_up++)
		h = h->pv;
	if (dist_dn < dist_up)
	{
		o = dist_dn;
//		while (dist_dn--)
//			exec(abo, "ra");
	}
	else
	{
		o = dist_up * -1;
//		while (dist_up--)
//			exec(abo, "rra");
	}
	return (o);
}

int		shortest_rotation_a_pivot(t_abo abo, int pivot)
{
	int	c;

	c = count_natural_rotation_a_pivot(abo, pivot);
	deb_("shortest_a_pivot\n");
	NL
	deb_(*abo.o);
	NL
	deb_int_(c);
//	static int d = 0; if (d++ > 44) exit (0);
	if (c < 0)
	{
		while (c++ < 0)
			exec(abo, "rra");
	}
	else
	{
		while (c-- > 0)
			exec(abo, "ra");
	}
	return (c);
}
