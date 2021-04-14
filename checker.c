/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 14:32:04 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			call_error(char **ops, int out)
{
	if (out == ER)
	{
		error_out();
		if (ops)
			ft_strfree2d(ops);
		return (-1);
	}
	if (out == KO)
	{
		ft_print_stdout("KO\n");
		if (ops)
			ft_strfree2d(ops);
		return (0);
	}
	return (-2);
}

int			end_routine(t_stk *stack_a, t_stk *stack_b, char **ops, int out)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	ft_print_stdout("Moves: ");
	if (ops)
		ft_print_x(ft_itoa(ft_strlen2d(ops)));
	else
		ft_print_stdout("none.");
	ft_print_stdout("\n");
	if (out == OK)
	{
		ft_strfree2d(ops);
		ft_print_stdout("OK\n");
	}
	else
		return (call_error(ops, out));
	return (0);
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
		op_exec(ops, &stack_a, &stack_b);
		if (estas_finita(stack_a, stack_b))
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
