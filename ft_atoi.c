/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:29:16 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:36:57 by fde-capu         ###   ########.fr       */
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

long long	ft_atoi(const char *str)
{
	char		*a[3];
	int			l;
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
		if (((*a[0] != '-') && (r > INT_MAX))
			|| ((*a[0] == '-') && (r * -1 < INT_MIN)))
			return (ft_ternary_i(*a[0] != '-', -1, 0));
		r *= ft_ternary_i(l, 10, 1);
	}
	r *= ft_ternary_i(*a[0] == '-', -1, 1);
	return (freec_and_retll(a[0], r));
}
