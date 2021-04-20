/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 07:42:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:33:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	st_sum_dign(char *a)
{
	int	s;

	s = 0;
	while (ft_isdigit(*a))
	{
		s++;
		a++;
	}
	return (s);
}

long long	ft_atol(const char *str)
{
	char		*a[3];
	long		l;
	long long	r;

	if ((!str) || (!*str))
		return (0);
	a[0] = ft_strtrim((char *)str, TRIM_SET);
	a[1] = a[0];
	if (*a[1] == '-' || *a[1] == '+')
		a[1]++;
	a[2] = a[1];
	l = 0 + st_sum_dign(a[1]);
	a[1] += st_sum_dign(a[1]);
	r = 0;
	a[1] = a[2];
	while ((l--) && (ft_isdigit(*a[1])))
	{
		r += (*a[1]++ - '0');
		if (((*a[0] != '-') && (r > LONG_MAX))
			|| ((*a[0] == '-') && (r * -1 < LONG_MIN)))
			return (ft_ternary_i(*a[0] != '-', -1, 0));
		r *= ft_ternary_i(l, 10, 1);
	}
	r *= ft_ternary_i(*a[0] == '-', -1, 1);
	return (freec_and_retll(a[0], r));
}
