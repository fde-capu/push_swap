/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:15:51 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
