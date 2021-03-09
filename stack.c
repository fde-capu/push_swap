/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:48:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 15:14:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stk	*stack_head(t_stk *stk)
{
	if (stk->pv)
		return (stack_head(stk->pv));
	return (stk);
}

t_stk	*stack_tail(t_stk *stk)
{
	if (stk->nx)
		return (stack_tail(stk->nx));
	return (stk);
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

t_stk	*init_stack(int argc, char **argv)
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

void	stack_log(t_stk *stk)
{
	char	*str;

	while (stk)
	{
		str = ft_strcatxl(ft_itoa(stk->val), "\n");
		ft_print_stdout(str);
		free(str);
		stk = stk->nx;
	}
	return ;
}

int		stack_size(t_stk *stk)
{
	if (stk->nx)
		return (1 + stack_size(stk->nx));
	return (1);
}

char	*stack_double_log_level(t_stk *a, t_stk *b)
{
	char	*line;

	if (a && b)
	{
		line = ft_itoa(a->val);
		line = ft_strcatxl(line, "\t");
		line = ft_strcatxx(line, ft_itoa(b->val));
		line = ft_strcatxl(line, "\n");
		return (line);
	}
	if (a)
	{
		line = ft_itoa(a->val);
		line = ft_strcatxl(line, "\n");
		return (line);
	}
	if (b)
	{
		line = ft_str("    \t");
		line = ft_strcatxx(line, ft_itoa(b->val));
		line = ft_strcatxl(line, "\n");
		return (line);
	}
	return (0);
}

void	stack_double_log(t_stk *a, t_stk *b)
{
	char	*line;
	char	*pile;

	pile = ft_strnew();
	line = ft_strnew();
	while (a || b)
	{
		pile = ft_strcatxx(pile, line);
		line = stack_double_log_level(a, b);
		if (a)
			a = a->nx;
		if (b)
			b = b->nx;
	}
	pile = ft_strcatxx(pile, line);
	ft_print_stdout(pile);
	free (pile);
	return ;
}
