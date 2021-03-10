/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 10:24:18 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	end_routine(t_stk *stack_a, t_stk *stack_b)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return (0);
}

int		validate_op(char *op)
{
	if (ft_check(op, " *"))
		return (0);
	if (ft_strstr(op, OP_NAMES))
		return (1);
	return (0);
}

void	gnl(void)
{
	char	*line;
	
	line = 0;
	while (get_next_line(0, &line))
	{
		if (validate_op(line))
			ft_print_stdout("valid");
		else
			ft_print_stdout("INvalid");
		free(line);
	}
	free(line);
	return ;
}

int	main(int argc, char **argv)
{
	t_stk	*stack_a;
	t_stk	*stack_b;

	if (validate_args(argc, argv))
	{
		stack_a = init_stack_from_args(argc, argv);
		stack_b = init_stack_empty();
		stack_double_log(stack_a, stack_b);
		gnl();
		exit(end_routine(stack_a, stack_b));
	}
	else
	{
		if (argc != 1)
			exit(error_out());
		exit (0);
	}
}
