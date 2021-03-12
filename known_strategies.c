/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   known_strategies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 08:55:25 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/12 12:42:52 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*gen_quicksort(t_stk **a, t_stk **b)
{
	char	*out;

	out = gen_split_low_high(a, b, 2);
	printf(">GO>\n");
	stack_double_log(*a, *b);
	return (out);
}

int		solve_sort(t_ttg *k, t_stk **a, t_stk **b)
{
	k->formula = (k->function)(a, b);
	return (0);
}

void	solve_known_strategies(t_ttg *k, t_stk *a)
{
	while (k)
	{
		k->a = stack_clone(a);
		solve_sort(k, &(k->a), &(k->b));
		k = k->nx;
	}
	return ;
}

t_ttg	**init_known_strategies(t_ttg **k)
{
	(*k) = ft_calloc(sizeof(t_ttg), 1);
	(*k)->function = gen_quicksort;
	//
	return (k);
}

void	strategy_destroy(t_ttg *k)
{
	if (k->nx)
		strategy_destroy(k->nx);
	k->nx = 0;
	free (k->formula);
	destroy_stack(k->a);
	destroy_stack(k->b);
	free (k);
	return ;
}
