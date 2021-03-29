/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_strategy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:49:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/29 15:51:33 by fde-capu         ###   ########.fr       */
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
	if (!*str)
		return (0);
	next_command(&str);
	return (1 + count_instructions_in_str(str));
}
