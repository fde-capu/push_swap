/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 08:20:50 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 21:33:19 by fde-capu         ###   ########.fr       */

/* ************************************************************************** */

#include "push_swap.h"

int				ps_try_bubble(t_stk **a, t_stk **b, char **o)
{
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val) && (*b) \
		&& ((*b)->nx) && ((*b)->val < (*b)->nx->val))
			ouch(a, b, o, "ss");
	if ((*a) && ((*a)->nx) \
		&& ((*a)->val > (*a)->nx->val))
			ouch(a, b, o, "sa");
	if ((*b) && ((*b)->nx) \
		&& ((*b)->val < (*b)->nx->val))
			ouch(a, b, o, "sb");
	return (estas_finita((*a), (*b)));
}

int				combo_rot(t_stk *a, t_stk *b)
{
	(void)a; (void)b;
	return (0);
}

int				ps_try_final_rotation(t_stk **a, t_stk **b, char **o)
{
	(void)o;
	return (estas_finita((*a), (*b)));
}

void			gen_fit_back(t_stk **a, t_stk **b, char **o)
{
	int	min_value;

	min_value = min_val(*a);
	while (is_(*b) \
		&& (((*b)->val < (*a)->val) \
		|| ((*a)->val == min_value)))
			ouch(a, b, o, "pa");
	return ;
}

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	ps_try_final_rotation(a, b, o);

//	if ((ps_try_bubble(a, b, o)) \
//		|| (ps_try_final_rotation(a, b, o)))
//			return ;
//	gen_split_low_high(a, b, stack_tail(*a)->val, o);
//	ps_try_bubble(a, b, o);
//	gen_fit_back(a, b, o);
//	if ((ps_try_bubble(a, b, o)) \
//		|| (ps_try_final_rotation(a, b, o)))
//			return ;
//	//gen_split_low_high(a, b, stack_tail(*a)->val, o);
//	//ps_try_bubble(a, b, o);
	return ;
}
