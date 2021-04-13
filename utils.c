/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:44:21 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 17:32:59 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_it_to_stdout(t_ttg *s)
{
	char	*h;

	if (DEBUG)
	{
		deb_int_(s->result);
		return ;
	}
	if (!(s->formula))
		return ;
	h = s->formula;
	while (*h)
	{
		if (*h == ',')
			write(1, "\n", 1);
		else
			write(1, h, 1);
		h++;
	}
	if (h != s->formula)
		write(1, "\n", 1);
	return ;
}

t_abo	make_abo(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;

	abo.a = a;
	abo.b = b;
	abo.o = o;
	return (abo);
}

int		min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int		any_in_quad_pivot(t_abo abo, int pivot[4])
{
	t_stk	*h;

	h = *abo.a;
	while (h)
	{
		if (h->val >= pivot[0] && h->val <= pivot[1])
			return (1);
		if (h->val >= pivot[2] && h->val <= pivot[3])
			return (1);
		h = h->nx;
	}
	return (0);
}
