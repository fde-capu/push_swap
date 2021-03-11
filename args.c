/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:24:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 23:38:44 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int				all_strict_int(int argc, char **argv)
{
	int		arg_i;
	int		*i_from_a;

	i_from_a = malloc(sizeof(int));
	arg_i = 0;
	while (++arg_i < argc)
	{
		if (!(strict_atoi(i_from_a, argv[arg_i])))
			return (0);
	}
	free(i_from_a);
	return (1);
}

int				chain_repeated(t_stk *stk)
{
	t_stk	*cmp;

	while (stk)
	{
		cmp = stk->nx;
		while (cmp)
		{
			if (cmp->val == stk->val)
				return (1);
			cmp = cmp->nx;
		}
		stk = stk->nx;
	}
	return (0);
}

int				unrepeated(int argc, char **argv)
{
	t_stk	*stk;
	int		is_it;

	stk = init_stack_from_args(argc, argv);
	is_it = chain_repeated(stk);
	destroy_stack(stk);
	return (!is_it);
}

int				validate_args(int argc, char **argv)
{
	if ((argc == 1) || (!(all_strict_int(argc, argv))) \
		|| (!(unrepeated(argc, argv))))
		return (0);
	return (1);
}

int				error_out(void)
{
	write(2, "Error\n", 6);
	return (1);
}
