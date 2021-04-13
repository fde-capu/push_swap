/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:57 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:03:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	deb_quad_pivot(int pivot[4])
{
	deb_("pivot:");
	deb_int_(pivot[0]);
	deb_int_(pivot[1]);
	deb_int_(pivot[2]);
	deb_int_(pivot[3]);
	return ;
}
