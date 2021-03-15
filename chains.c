/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 09:02:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				pw_try_buble_it(t_stk **a, t_stk **b, char **o)
{
	if ((*a) && ((*a)->nx) && ((*a)->val > (*a)->nx->val) && (*b) && ((*b)->nx) && ((*b)->val < (*b)->nx->val))
		ouch(a, b, o, "ss");
	if ((*a) && ((*a)->nx) && ((*a)->val > (*a)->nx->val))
		ouch(a, b, o, "sa");
	if ((*b) && ((*b)->nx) && ((*b)->val < (*b)->nx->val))
		ouch(a, b, o, "sb");
	return (estas_finita((*a), (*b)));
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	if (pw_try_buble_it(a, b, o))
		return ;
	return ;
}
