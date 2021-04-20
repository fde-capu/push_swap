/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:34:40 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 21:19:36 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	isneedle(char *h, char *n)
{
	while ((*h == *n) && *h)
	{
		h++;
		n++;
	}
	if (*n)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	int		nl;

	h = (char *)haystack;
	n = (char *)needle;
	if (ft_strlen(n) > ft_strlen(h))
		return (NULL);
	if ((!*n) || ((*n == 0) && (len == 0)) || (needle == haystack))
		return (h);
	nl = 0;
	while (*++n)
		nl++;
	n = (char *)needle;
	while (*h && len)
	{
		if ((isneedle(h, n)) && ((int)len - nl > 0))
			return (h);
		h++;
		len--;
	}
	return (NULL);
}

/*
**	ft_strstr :: twisted version of above.
**  = find (this on this), give me address or nothing'.
*/

char	*ft_strstr(const char *a, const char *b)
{
	return (ft_strnstr(b, a, ft_strlen(b)));
}

int	ft_strbegins(const char *str, const char *beg)
{
	if (ft_strstr(beg, str) == str)
		return (1);
	return (0);
}

int	ft_strbeginsxl(char *str, char *beg)
{
	int	o;

	o = ft_strbegins(str, beg);
	free(str);
	return (o);
}
