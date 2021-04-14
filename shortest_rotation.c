/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 00:56:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		tricky_walk_a_atob(t_abo abo, int pivot)
{
	t_stk	*dn;
	t_stk	*up;
	
	dn = *abo.a;
	up = *abo.a;
	while (up->val > pivot && dn->val > pivot)
	{
		up = pv(up);
		dn = nx(dn);
	}
	if (up->val <= pivot)
		top_a(abo, cell_by_val(*abo.a, up->val));
	else
		top_a(abo, cell_by_val(*abo.a, dn->val));
	return (1);
}

void	shortest_rotation_dir_pivot(t_abo abo, int dir, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	t_stk	**a;
	t_stk	**b;

	(void)dir;
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

int		shortest_a_atob(t_abo abo, int pivot)
{
	shortest_rotation_dir_pivot(abo, ATOB, pivot);
	return (1);
//	return (tricky_walk_a_atob(abo, pivot));
}

int		tricky_walk_b_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	n = count_natural_b_give(abo);
	r = count_reverse_b_give(abo);
	l = count_lasts_ra(abo);
	op = rot_solve(n, r, l);
	return (op);
}

int		shortest_b_btoa(t_abo abo)
{
	int	op;

	deb_("shortest_b_btoa\n");
	if (!abo.b || !*abo.b)
		return (0);
	op = tricky_walk_b_btoa(abo);
	deb_int_(op);
	if (op > 0)
	{
		while (op-- > 0)
		{
			exec(abo, "rb");
			op -= spot(abo, "pa");
		}
	}
	else
	{
		while (op++ < 0)
		{
			exec(abo, "rrb");
			spot(abo, "pa");
		}
	}
	return (spot_dn(abo));
}

int		tricky_walk_a_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	n = count_natural_a_receive(abo);
	r = count_reverse_a_receive(abo);
	l = count_lasts_rb(abo);
	op = rot_solve(n, r, l);
	return (op);
}

int		shortest_a_btoa(t_abo abo)
{
	int	op;

	deb_("shortest_a_btoa\n");
	op = tricky_walk_a_btoa(abo);
	if (op > 0)
	{
		while (op-- > 0)
		{
			exec(abo, "ra");
			if (spot(abo, "pa"))
				return (0);
		}
		return (1);
	}
	if (op < 0)
	{
		while (op++ < 0)
		{
			exec(abo, "rra");
			if (spot(abo, "pa"))
				return (0);
		}
		return (1);
	}
	return (-1);
}

void	moderate_shortest_rotation_b_receive(t_abo abo)
{
	int		c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return ;
	deb_("moderate_shortest_rotation_b_receive\n");
	c = calc_top_b(abo, b_before_a(abo));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h, *abo.o), "ra"))
			exec(abo, "rb");
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h, *abo.o), "rra"))
			exec(abo, "rrb");
	}
	return ;
}
