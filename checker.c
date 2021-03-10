/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 14:53:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			end_routine(t_stk *stack_a, t_stk *stack_b, char **ops, int out)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	ft_strfree2d(ops);
	if (out)
		error_out();
	return (out);
}

int			main(int argc, char **argv)
{
	t_stk	*stack_a;
	t_stk	*stack_b;
	char	**ops;

	ops = 0;
	if (validate_args(argc, argv) && (validate_stdin_ops(&ops)))
	{
		stack_a = init_stack_from_args(argc, argv);
		stack_b = init_stack_empty();
		stack_double_log(stack_a, stack_b);
		exit(end_routine(stack_a, stack_b, ops, 0));
	}
	else
		if (argc != 1)
			exit(error_out());
	exit (0);
}
