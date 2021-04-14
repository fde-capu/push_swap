/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:13:54 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 13:12:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flush_a(t_abo abo)
{
	top_a(abo, min_cell(*abo.a));
	return ;
}

void	shortest_rotation_b_receive(t_abo abo)
{
	t_stk	*bba;

	if (!abo.b || !*abo.b)
		return ;
	bba = b_before_a(abo);
	top_b(abo, bba);
	return ;
}
