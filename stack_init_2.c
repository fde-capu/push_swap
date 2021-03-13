/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:41:39 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/12 13:26:48 by fde-capu         ###   ########.fr       */
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

int			is_in_order(t_stk *s)
{
	int		max_control;

	if ((!s) || (stack_size(s) == 1))
		return (1);
	max_control = s->val;
	while (s)
	{
		if (s->val < max_control)
			return (0);
		if (s->val > max_control)
			max_control = s->val;
		s = s->nx;
	}
	return (1);
}
