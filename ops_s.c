/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:20:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 18:07:03 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	switch_top(t_stk **s)
{
	if (stack_size(*s) <= 1)
		return ;
	(*s) = (*s)->nx;
	(*s)->pv->nx = (*s)->nx;
	(*s)->nx = (*s)->pv;
	(*s)->pv = 0;
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
