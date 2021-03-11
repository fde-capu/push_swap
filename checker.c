/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/11 00:20:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			end_routine(t_stk *stack_a, t_stk *stack_b, char **ops, int out)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	if (out == ER)
	{
		error_out();
		ft_strfree2d(ops);
		return (-1);
	}
	if (out == KO)
	{
		ft_print_stdout("KO\n");
		ft_strfree2d(ops);
		return (0);
	}
	if (out == OK)
	{
		ft_print_stdout("OK\nMoves: ");
		ft_print_x(ft_itoa(ft_strlen2d(ops)));
		ft_print_stdout("\n");
		ft_strfree2d(ops);
	}
	return (0);
}

int			is_in_order(t_stk *s)
{
	int		max_control;

	if (!s)
		return (0);
	max_control = s->val;
	while (s)
	{
		if (s->val < max_control)
			return (0);
		if (s->val > max_control)
			max_control = s->val;
		s = s->nx;
	}
	return (1);
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
		ft_print_stdout("\nInitial:\n\n");
		stack_double_log(stack_a, stack_b);
		op_exec(ops, &stack_a, &stack_b);
		ft_print_stdout("Final:\n\n");
		stack_double_log(stack_a, stack_b);
		if (is_in_order(stack_a) && !(stack_size(stack_b)))
			exit(end_routine(stack_a, stack_b, ops, OK));
		exit(end_routine(stack_a, stack_b, ops, KO));
	}
	else
	{
		if (argc != 1)
			exit(error_out());
	}
	exit(0);
}
