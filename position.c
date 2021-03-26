/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:58:08 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/26 08:17:54 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				position_top(t_stk *a, t_stk *h)
{
	if (!h)
		return (-1);
	return (position_top(a, h->pv) + 1);
}

int				position_bot(t_stk *a, t_stk *h)
{
	if (!h)
		return (0);
	return (position_bot(a, h->nx) + 1);
}

int		calc_cell_on_top_b(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*b, cell);
	dist_bot = position_bot(*b, cell);
	if (dist_top < dist_bot)
		return (dist_top);
	else
		return (dist_bot);
	(void)a;
	(void)o;
}

int		calc_cell_on_top_a(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*a, cell);
	dist_bot = position_bot(*a, cell);
	if (dist_top < dist_bot)
		return (dist_top);
	else
		return (dist_bot);
	(void)b;
	(void)o;
}

void	put_cell_on_top_a(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*a, cell);
	dist_bot = position_bot(*a, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			ouch(a, b, o, "ra");
	}
	else
	{
		while (dist_bot--)
			ouch(a, b, o, "rra");
	}
	return ;
}

void	put_cell_on_top_b(t_stk **a, t_stk **b, char **o, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;

	if (!cell)
		return ;
	dist_top = position_top(*b, cell);
	dist_bot = position_bot(*b, cell);
	if (dist_top < dist_bot)
	{
		while (dist_top--)
			ouch(a, b, o, "rb");
	}
	else
	{
		while (dist_bot--)
			ouch(a, b, o, "rrb");
	}
	return ;
}
