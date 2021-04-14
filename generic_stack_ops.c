/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_stack_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 12:56:00 by fde-capu         ###   ########.fr       */
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

int		count_le(t_stk *h, int about)
{
	if (!h)
		return (0);
	if (h->val <= about)
		return (count_le(h->nx, about) + 1);
	else
		return (count_le(h->nx, about));
}
