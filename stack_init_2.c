/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:41:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 13:08:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_stk	*stack_init(char *stk_str)
{
	int		argc;
	char	**argv;
	t_stk	*out;

	stk_str = ft_strcat("foo,", stk_str);
	argv = ft_split(stk_str, ',');
	argc = ft_strlen2d(argv);
	out = init_stack_from_args(argc, argv);
	ft_strfree2d(argv);
	free (stk_str);
	return (out);
}

int			in_order(t_stk *s)
{
	int		control;

	if ((!s) || (stack_size(s) == 1))
		return (1);
	control = s->val;
	while (s)
	{
		if (s->val < control)
			return (0);
		if (s->val > control)
			control = s->val;
		s = s->nx;
	}
	return (1);
}

int			in_reverse(t_stk *s)
{
	int		control;

	if ((!s) || (stack_size(s) == 1))
		return (1);
	control = s->val;
	while (s)
	{
		if (s->val > control)
			return (0);
		if (s->val < control)
			control = s->val;
		s = s->nx;
	}
	return (1);
}

void		str_replace_chr_chr(char **str, char this, char to_this)
{
	char	*h;

	h = *str;
	while (*h)
	{
		if (*h == this)
			*h = to_this;
		h++;
	}
	return ;
}

int			estas_finita(t_stk *a, t_stk *b)
{
	if (in_order(a) && !(stack_size(b)))
		return (1);
	return (0);
}
