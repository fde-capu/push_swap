/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:55:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 00:27:33 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stk	*init_stack_empty(void)
{
	t_stk	*stk;

	stk = ft_calloc(sizeof(t_stk), 1);
	stk->empty = 1;
	return (stk);
}

t_stk	*stack_chain_init(int argc, char **argv)
{
	t_stk	*stk;
	int		*i_from_a;

	i_from_a = malloc(sizeof(int));
	if (!(strict_atoi(i_from_a, argv[argc - 1])))
		return (0);
	stk = ft_calloc(sizeof(t_stk), 1);
	stk->val = *i_from_a;
	free(i_from_a);
	if (argc > 1)
		stk->pv = stack_chain_init(--argc, argv);
	return (stk);
}

t_stk	*init_stack_from_args(int argc, char **argv)
{
	t_stk	*stk;

	stk = stack_chain_init(argc, argv);
	stk = stack_chain_next(stk);
	return (stack_head(stk));
}

void	destroy_stack(t_stk *stk)
{
	if (stk->nx)
		destroy_stack(stk->nx);
	free(stk);
	return ;
}

t_stk	*stack_chain_next(t_stk *stk)
{
	if (stk->pv)
	{
		stk->pv->nx = stk;
		stack_chain_next(stk->pv);
	}
	return (stack_head(stk));
}
