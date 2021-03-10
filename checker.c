/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 13:36:32 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			end_routine(t_stk *stack_a, t_stk *stack_b, int out)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	if (out)
		error_out();
	return (out);
}

int			validate_op(char *op)
{
	if (ft_check(op, " "))
		return (0);
	if (ft_strstr(op, OP_NAMES))
		return (1);
	return (0);
}

int			gnl(t_stk *a, t_stk *b)
{
	char	*line;
	
	line = 0;
	while (get_next_line(0, &line))
	{
		if (validate_op(line))
			op_exec(line, &a, &b);
		else
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stk	*stack_a;
	t_stk	*stack_b;

	if (validate_args(argc, argv))
	{
		stack_a = init_stack_from_args(argc, argv);
		stack_b = init_stack_empty();
		stack_double_log(stack_a, stack_b);
		stack_log(stack_b);
		if (gnl(stack_a, stack_b))
			exit(end_routine(stack_a, stack_b, 0));
		else
			exit(end_routine(stack_a, stack_b, 1));
	}
	else
		if (argc != 1)
			exit(error_out());
	exit (0);
}
