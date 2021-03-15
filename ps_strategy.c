/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/12 23:37:38 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	strategy_destroy(t_ttg *k)
{
	free (k->formula);
	destroy_stack(k->a);
	destroy_stack(k->b);
	free (k);
	return ;
}

int		count_instructions_in_str(char *str)
{
	static int	c = 0;

	if (!*str)
		return (c + 1);
	if (*str == ',')
		c++;
	if (*str)
		return (count_instructions_in_str(++str));
	return (0);
}

void	give_it_to_stdout(t_ttg *s)
{
	char	*h;

	h = s->formula;
	while (*h)
	{
		if (*h == ',')
			write(1, "\n", 1);
		else
			write(1, h, 1);
		h++;
	}
	write(1, "\n", 1);
	return ;
}
