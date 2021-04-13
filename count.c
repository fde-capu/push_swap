/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:01:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 14:36:27 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_reverse_b_give(t_abo abo)
{
	int		dist_top;
	int		dist_bot;
	t_stk	*cell;

	cell = b_before_a(abo);
	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.b, cell);
	dist_bot = position_bot(*abo.b, cell);
	if (dist_top >= dist_bot)
		return (dist_top);
	else
		return (dist_bot);
}

int		count_lasts_rb(t_abo abo)
{
	char	*h;
	int		c;

	c = 0;
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rb"))
		c++;
	if (c)
		return (c);
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rrb"))
		c--;
	return (c);
}

int		count_lasts_ra(t_abo abo)
{
	char	*h;
	int		c;

	c = 0;
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "ra"))
		c++;
	if (c)
		return (c);
	h = *abo.o + ft_strlen(*abo.o);
	while (ft_strbegins(prev_command(&h, *abo.o), "rra"))
		c--;
	return (c);
}

int		count_natural_a_receive(t_abo abo)
{
	return (calc_top_a(abo, a_after_b(abo)));
}

int		count_reverse_a_receive(t_abo abo)
{
	int		dist_top;
	int		dist_bot;
	t_stk	*cell;

	cell = a_after_b(abo);
	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.a, cell);
	dist_bot = position_bot(*abo.a, cell);
	if (dist_top >= dist_bot)
		return (dist_top);
	else
		return (dist_bot);
}
