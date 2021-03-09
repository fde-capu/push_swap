/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:24:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 07:45:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int				init_arg(t_stk **arg_dst, char *argv)
{
	int	*i_from_a;

	i_from_a = malloc(sizeof(int));
	if (!(strict_atoi(i_from_a, argv)))
		return (0);
	*arg_dst = malloc(sizeof(t_stk));
	free(i_from_a);
	return (1);
}

int				validate_args(int argc, char **argv)
{
	t_stk	*arg_dst;
	int		arg_i;

	if (argc == 1)
		return (0);
	arg_i = 0;
	while (++arg_i < argc)
	{
		if (!(init_arg(&arg_dst, argv[arg_i])))
			return (0);
		free(arg_dst);
	}
	return (1);
}

void			error_out(void)
{
	write(2, "Error\n", 6);
	return ;
}
