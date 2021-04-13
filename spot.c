/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:06:43 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:08:05 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	spot_up(t_abo abo)
{
	t_stk	*c;

	deb_("spot_up (a to b)? ");
	c = b_before_a(abo);
	if (c == *abo.b && stack_size(*abo.b) >= 2)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int	spot_dn(t_abo abo)
{
	t_stk	*c;

	deb_("spot_dn (b to a)? ");
	c = a_after_b(abo);
	if (c == *abo.a && stack_size(*abo.a) >= 2)
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int	spot(t_abo abo, char *op)
{
	int	c;

	deb_("Spot!\n");
	c = 0;
	if (ft_stridentical(op, "pb"))
	{
		while (spot_up(abo))
		{
			exec(abo, op);
			c++;
		}
	}
	if (ft_stridentical(op, "pa"))
	{
		while (spot_dn(abo))
		{
			exec(abo, op);
			c++;
		}
	}
	return (c);
}
