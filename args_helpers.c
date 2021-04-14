/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:00:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 13:03:46 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	strict_atoi(int *i_from_a, const char *argv)
{
	long	int_bounds;

	int_bounds = ft_atol(argv);
	if ((!(ft_check(argv, "[-+]?[0123456789]+$")))
	|| ((int_bounds < INT_MIN) || (int_bounds > INT_MAX))
	|| (ft_check(argv, "[-+]$")))
	{
		free(i_from_a);
		return (0);
	}
	*i_from_a = ft_atoi(argv);
	return (1);
}
