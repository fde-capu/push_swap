/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:20:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/17 17:09:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	switch_top(t_stk **s)
{
	t_stk	*second;
	t_stk	*first;
	t_stk	*third;

	if (stack_size(*s) <= 1)
		return ;
	first = (*s)->nx;
	second = (*s);
	third = (*s)->nx->nx;
	if (third)
		third->pv = second;
	second->pv = first;
	first->pv = 0;
	first->nx = second;
	if (third)
		second->nx = third;
	else
		second->nx = 0;
	(*s) = first;
	return ;
}

void	sa(t_stk **a, t_stk **b)
{
	switch_top(a);
	(void)b;
	return ;
}

void	sb(t_stk **a, t_stk **b)
{
	switch_top(b);
	(void)a;
	return ;
}

void	ss(t_stk **a, t_stk **b)
{
	switch_top(a);
	switch_top(b);
	return ;
}
