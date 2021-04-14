/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:58:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 13:30:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		position_top(t_stk *a, t_stk *h)
{
	if (!h)
		return (-1);
	return (position_top(a, h->pv) + 1);
}

int		position_bot(t_stk *a, t_stk *h)
{
	if (!h)
		return (0);
	return (position_bot(a, h->nx) + 1);
}

void	top_a(t_abo abo, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*abo.a, cell);
	dist_bot = position_bot(*abo.a, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			exec(abo, "ra");
	}
	else
	{
		while (dist_bot--)
			exec(abo, "rra");
	}
	return ;
}

void	top_b(t_abo abo, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*abo.b, cell);
	dist_bot = position_bot(*abo.b, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			exec(abo, "rb");
	}
	else
	{
		while (dist_bot--)
			exec(abo, "rrb");
	}
	return ;
}
