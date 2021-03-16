/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 13:20:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		count_gt(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val > about)
		return (count_gt(h->nx, about) + 1);
	else
		return (count_gt(h->nx, about));
}

int		count_le(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val <= about)
		return (count_le(h->nx, about) + 1);
	else
		return (count_le(h->nx, about));
}

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

void	re_ouch(t_stk **a, t_stk **b, char **o, char *ops)
{
//	printf("re_ouch '%s'\n", ops);
	(void)a; (void)b; (void)o; (void)ops;
	return ;
}

void	pre_ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	t_stk	*pre_a;
	t_stk	*pre_b;

	pre_a = stack_clone(*a);
	pre_b = stack_clone(*b);
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, &pre_a, &pre_b);
	destroy_stack(pre_a);
	destroy_stack(pre_b);
	return ;
}

void	ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, a, b);
	return ;
}
