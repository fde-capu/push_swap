/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:57:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 21:11:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		full_rot_a_quad(t_abo abo, int pivot[4])
{
	deb_("full_rot_a_quad\n");
	while (!(is_in_quad((*abo.a)->val, pivot)))
		exec(abo, "ra");
	return (1);
}

int		soft_slice(t_abo abo)
{
	(void)abo;
	if (stack_size(*abo.a) <= 5)
		return (1);
	return (2);
}

t_stk	*stack_x(t_stk *old, t_stk *new)
{
	destroy_stack(old);
	return (new);
}

void	exec(t_abo abo, char *op)
{
	ouch(abo.a, abo.b, abo.o, op);
	return ;
}

int		ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, a, b);
	if (DEBUG == 1)
	{
		ft_print_stdout(op);
		ft_print_stdout(":\n");
		stack_double_log(*a, *b);
	}
	return (1);
}
