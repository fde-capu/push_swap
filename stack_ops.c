/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:57:28 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 13:36:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	op_exec(char *op, t_stk **stack_a, t_stk **stack_b)
{
	t_stk	*a;
	t_stk	*b;

	a = *stack_a;
	b = *stack_b;
	printf(">>> %s ::: %d ::: %d\n", op, a->val, b->val);
	return ;
}
