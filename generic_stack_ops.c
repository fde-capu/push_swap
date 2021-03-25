/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 10:57:55 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		count_gt(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val > about)
		return (count_gt(h->nx, about) + 1);
	else
		return (count_gt(h->nx, about));
}

int		count_le_len(t_stk *h, int about, int len)
{
	if (!h || !len)
		return (0);
	if (h->val <= about)
		return (count_le_len(h->nx, about + 1, --len));
	else
		return (count_le_len(h->nx, about, --len));
}

int		count_le(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val <= about)
		return (count_le(h->nx, about) + 1);
	else
		return (count_le(h->nx, about));
}

int		all_lowereq(t_stk *h, int about)
{
	while (h)
	{
		if (h->val > about)
			return (0);
		h = h->nx;
	}
	return (1);
}

void	get_put_dump(t_stk **a, t_stk **b, char **o)
{
	while (*b)
	{
		*o = ft_strcatxl(*o, ",pa");
		pa(a, b);
	}
	return ;
}
