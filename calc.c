/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:09:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:38:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_top_b(t_abo abo, t_stk *cell)
{
	int		dist_top;
	int		dist_bot;
	int		o;

	if (!cell)
		return (INT_MAX);
	dist_top = position_top(*abo.b, cell);
	dist_bot = position_bot(*abo.b, cell);
	if (dist_top < dist_bot)
		o = dist_top;
	else
		o = dist_bot * -1;
	return (o);
}
