/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:02:07 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_a(t_abo abo)
{
	top_a(abo, min_cell(*abo.a));
	return ;
}

void	shortest_rotation_b_receive(t_abo abo)
{
	t_stk	*bba;

	if (!abo.b || !*abo.b)
		return ;
	bba = b_before_a(abo);
	top_b(abo, bba);
	return ;
}

void	shortest_rotation_b_give(t_abo abo)
{
	top_b(abo, b_before_a(abo));
	return ;
}

int		opportunistic_b_receive(t_abo abo)
{
	int	c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return (0);
	deb_("opportunistic_b_receive\n");
	c = calc_top_b(abo, b_before_a(abo));
	deb_("mod:");
	deb_int_(c);
	deb_("\n");
	h = *abo.o + ft_strlen(*abo.o);
	if (c > 0)
	{
		while (c-- && ft_strbegins(prev_command(&h, *abo.o), "ra"))
		{
			exec(abo, "rb");
			c -= spot(abo, "pb");
		}
	}
	if (c < 0)
	{
		while (c++ && ft_strbegins(prev_command(&h, *abo.o), "rra"))
		{
			exec(abo, "rrb");
			c -= spot(abo, "pb");
		}
	}
	return (1);
}

int		opportunistic_flush_b(t_abo abo)
{
	int	w;
	char	*op;

	deb_("\nopportunistic_flush_b:");
	w = calc_top_b(abo, max_cell(*abo.b));
	if (w < 0)
	{
		op = ft_str("rrb");
		w *= -1;
	}
	else
		op = ft_str("rb");
	while (w > 0)
	{
		w -= spot(abo, "pa");
		exec(abo, op);
		w--;
	}
	free(op);
	deb_("done!\n");
	return (0);
}

int	shortest_b_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	deb_("shortest_b_btoa\n");
	if (!abo.b || !*abo.b)
		return (0);
	n = count_natural_b_give(abo);
	r = count_reverse_b_give(abo);
	l = count_lasts_ra(abo);
	op = rot_solve(n, r, l);
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

int	shortest_a_btoa(t_abo abo)
{
	int	n;
	int	r;
	int	l;
	int	op;

	deb_("shortest_a_btoa\n");
	n = count_natural_a_receive(abo);
	r = count_reverse_a_receive(abo);
	l = count_lasts_rb(abo);
	op = rot_solve(n, r, l);
	if (op > 0)
	{
		while (op-- > 0)
		{
			exec(abo, "ra");
			if(spot(abo, "pa"))
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

int	full_rot_a_quad(t_abo abo, int pivot[4])
{
	deb_("full_rot_a_quad\n");
	while (!(is_in_quad((*abo.a)->val, pivot)))
		exec(abo, "ra");
	return (1);
}

void			moderate_shortest_rotation_b_receive(t_abo abo)
{
	int	c;
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
