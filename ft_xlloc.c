/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 02:46:48 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 14:23:26 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Frees arg1, returns arg2.
*/

void	*ft_xlloc(void *arg1, void *arg2)
{
	if (arg1)
		free(arg1);
	return (arg2);
}

void	*ft_x(void *a1, void *a2)
{
	return (ft_xlloc(a1, a2));
}
