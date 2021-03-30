/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/30 10:06:51 by fde-capu         ###   ########.fr       */
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

void	count_loc_instructions(int c[TEST_NUM], t_abo loc[TEST_NUM])
{
	int	i;

	i = -1;
	while (++i < TEST_NUM)
	{
		c[i] = count_instructions_in_str(*loc[i].o);
		deb_int_(c[i]);
	}
	return ;
}

int		count_instructions_in_str(char *str)
{
	if (!*str)
		return (0);
	next_command(&str);
	return (1 + count_instructions_in_str(str));
}
