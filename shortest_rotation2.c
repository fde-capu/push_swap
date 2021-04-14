/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:13:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 20:56:29 by fde-capu         ###   ########.fr       */
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
	int		c;
	char	*h;

	if (stack_size(*abo.b) <= 1)
		return (0);
	deb_("opportunistic_b_receive\n");
	c = calc_top_b(abo, b_before_a(abo));
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
	int		w;
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
