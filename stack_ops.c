/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:57:28 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 21:27:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	op_run_str(char *o, t_stk **a, t_stk **b)
{
	if (ft_stridentical(o, "sa"))
		sa(a, b);
	if (ft_stridentical(o, "sb"))
		sb(a, b);
	if (ft_stridentical(o, "ss"))
		ss(a, b);
	if (ft_stridentical(o, "pa"))
		pa(a, b);
	if (ft_stridentical(o, "pb"))
		pb(a, b);
	if (ft_stridentical(o, "ra"))
		ra(a, b);
	if (ft_stridentical(o, "rb"))
		rb(a, b);
	if (ft_stridentical(o, "rr"))
		rr(a, b);
	if (ft_stridentical(o, "rra"))
		rra(a, b);
	if (ft_stridentical(o, "rrb"))
		rrb(a, b);
	if (ft_stridentical(o, "rrr"))
		rrr(a, b);
	return ;
}

void	op_exec(char **ops, t_stk **stack_a, t_stk **stack_b)
{
	if (!ops)
		return ;
	while (*ops)
	{
		op_run_str(*ops, stack_a, stack_b);
		ops++;
	}
	return ;
}

int			is_(t_stk *s)
{
	if (!s)
		return (0);
	return (1);
}

