/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 12:32:09 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pw_try_bubble_it(t_stk **a, t_stk **b, char **o)
{
	if ((*a) && ((*a)->nx) && ((*a)->val > (*a)->nx->val) && (*b) && ((*b)->nx) && ((*b)->val < (*b)->nx->val))
		ouch(a, b, o, "ss");
	if ((*a) && ((*a)->nx) && ((*a)->val > (*a)->nx->val))
		ouch(a, b, o, "sa");
	if ((*b) && ((*b)->nx) && ((*b)->val < (*b)->nx->val))
		ouch(a, b, o, "sb");
	return (estas_finita((*a), (*b)));
}

int				ps_try_final_rotation(t_stk **a, t_stk **b, char **o)
{
	if (is_(*b))
		return (0);
	if (is_in_order_rot(*a, o, TEST, 'a'))
		is_in_order_rot(*a, o, EXEC, 'a');
	return (estas_finita((*a), (*b)));
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	if ((pw_try_bubble_it(a, b, o)) || (ps_try_final_rotation(a, b, o)))
		return ;
	//gen_split_low_high(a, b, stack_tail(*a)->val, o);
	//get_put_dump(a, b, o);
	return ;
}
