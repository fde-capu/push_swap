/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:32:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 14:00:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	stack_log(t_stk *stk)
{
	char	*str;

	while (stk)
	{
		if (!(stk->empty))
		{
			str = ft_strcatxl(ft_itoa(stk->val), "\n");
			ft_print_stdout(str);
			free(str);
		}
		else
			ft_print_stdout("(empty)\n");
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
	t_stk	*stk[2];

	stk[0] = a;
	stk[1] = b;
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
	pile = ft_strcatxl(pile, "___\t___\n(");
	pile = ft_strcatxx(pile, ft_itoa(stack_size(stk[0])));
	pile = ft_strcatxl(pile, ")\t(");
	pile = ft_strcatxx(pile, ft_itoa(stack_size(stk[1])));
	pile = ft_strcatxl(pile, ")\n");
	pile = ft_strcatxl(pile, " a \t b \n");
	ft_print_stdout(pile);
	free (pile);
	return ;
}
