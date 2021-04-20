/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:27:03 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:02:22 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

long	long_abs(int n)
{
	if (n < 0)
		return ((long)n * -1);
	return ((long)n);
}

long	divide_by_ten(long *t)
{
	*t = *t / 10;
	return (*t);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*w;
	long			t;
	char			*r;

	t = long_abs(n);
	len = 1;
	if (n < 0)
		len++;
	while (divide_by_ten(&t))
		len++;
	r = ft_calloc(sizeof(char) * (len + 1), 1);
	if (!r)
		return (NULL);
	w = r + len;
	*w-- = 0;
	*w = '0';
	if (!n)
		return (r);
	t = long_abs(n) * 10;
	while (divide_by_ten(&t))
		*w-- = (t % 10) + '0';
	if (n < 0)
		*w = '-';
	return (r);
}
