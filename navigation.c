/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:42:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 12:04:49 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_b_pb(t_abo abo)
{
	shortest_rotation_b_receive(abo);
	exec(abo, "pb");
	return ;
}

t_stk	*nx(t_stk *h)
{
	if (h->nx)
		return (h->nx);
	return (stack_head(h));
}

t_stk	*pv(t_stk *h)
{
	if (h->pv)
		return (h->pv);
	return (stack_tail(h));
}
