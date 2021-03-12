/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/12 13:15:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		all_lowereq(t_stk *h, int about)
{
	while (h)
	{
		if (h->val > about)
			return (0);
		h = h->nx;
	}
	return (1);
}

void	get_put_dump(t_stk **a, t_stk **b, char **o)
{
	while (*b)
	{
		*o = ft_strcatxl(*o, ",pa");
		pa(a, b);
	}
	return ;
}

void	ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, a, b);
}

char	*gen_split_low_high(t_stk **a, t_stk **b, int about)
{
	t_stk	*h;
	char	*o;

	o = ft_str("");
	h = *a;
	printf("XXXXXXX\n");
	stack_double_log(*a, *b);
	while (!(all_lowereq(h, about)))
	{
		if (h->val > about)
			ouch(a, b, &o, "pb");
		else
			ouch(a, b, &o, "rra");
		h = *a;
	}
	get_put_dump(a, b, &o),
	o = ft_x(o, ft_str(o + 1));
	printf("out: %s--\n", o);
	return (o);
}
