/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 00:15:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	end_routine(t_stk *stack_a, t_stk *stack_b)
{
	destroy_stack(stack_a);
	destroy_stack(stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*stack_a;
	t_stk	*stack_b;

	if (validate_args(argc, argv))
	{
		stack_a = init_stack_from_args(argc, argv);
		stack_log(stack_a);
		stack_b = init_stack_from_args(5, ft_split("foo,7,8,9,10", ','));
		stack_log(stack_b);
		stack_double_log(stack_a, stack_b);
		printf("valid ");
		exit(end_routine(stack_a, stack_b));
	}
	else
	{
		if (argc != 1)
			error_out();
	}
	exit (0);
}
