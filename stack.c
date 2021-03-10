/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 06:48:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 00:32:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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

char	*stack_double_log_level(t_stk *a, t_stk *b)
{
	char	*line;

	if ((a && b) && (!(a->empty) && !(b->empty)))
	{
		line = ft_itoa(a->val);
		line = ft_strcatxl(line, "\t");
		line = ft_strcatxx(line, ft_itoa(b->val));
		line = ft_strcatxl(line, "\n");
		return (line);
	}
	if ((a) && !(a->empty))
	{
		line = ft_itoa(a->val);
		line = ft_strcatxl(line, "\n");
		return (line);
	}
	if ((b) && !(b->empty))
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
	ft_print_stdout("---\t---\n a \t b \n");
	free (pile);
	return ;
}
