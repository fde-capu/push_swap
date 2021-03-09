/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:12:58 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 07:48:20 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	end_routine(t_stk *stack_a)
{
	destroy_stack(stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stk	*stack_a;

	if (validate_args(argc, argv))
	{
		stack_a = init_stack(argc, argv);
		stack_log(stack_a);
		printf("valid ");
		exit(end_routine(stack_a));
	}
	else
	{
		if (argc != 1)
			error_out();
	}
	exit (0);
}
