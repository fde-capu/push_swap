/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_logs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:32:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/11 00:18:45 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	stack_log(t_stk *stk)
{
	char	*str;
	int		something;

	something = 0;
	while (stk)
	{
		str = ft_strcatxl(ft_itoa(stk->val), "\n");
		ft_print_stdout(str);
		free(str);
		something = 1;
		stk = stk->nx;
	}
	if (!something)
		ft_print_stdout("(empty)\n");
	return ;
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

void	stack_double_log_bottom(int size_a, int size_b)
{
	char	*pile;

	pile = ft_str("___\t___\n(");
	pile = ft_strcatxx(pile, ft_itoa(size_a));
	pile = ft_strcatxl(pile, ")\t(");
	pile = ft_strcatxx(pile, ft_itoa(size_b));
	pile = ft_strcatxl(pile, ")\n a \t b \n\n");
	ft_print_stdout(pile);
	free(pile);
	return ;
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
	ft_print_stdout(pile);
	stack_double_log_bottom(stack_size(stk[0]), stack_size(stk[1]));
	free(pile);
	return ;
}
