/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:48:09 by fde-capu          #+#    #+#             */
/*   Updated: 2020/05/14 16:55:19 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		findnl(char *s)
{
	while ((s) && (*s))
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

int		len(char *s)
{
	int	c;

	c = 0;
	while ((s) && (*s))
	{
		s++;
		c++;
	}
	return (c);
}

char	*concat(char *str_a, char *str_b)
{
	char	*out;
	char	*p;
	char	*a;
	char	*b;

	out = malloc(len(str_a) + len(str_b) + 1);
	p = out;
	a = str_a;
	b = str_b;
	while ((a) && (*a))
	{
		*p = *a;
		p++;
		a++;
	}
	while ((b) && (*b))
	{
		*p = *b;
		p++;
		b++;
	}
	*p = 0;
	free(str_a);
	return (out);
}

void	dosave(char *l, char *s)
{
	while ((l) && (*l) && (*l != '\n'))
		l++;
	if (*l == '\n')
	{
		*l = 0;
		l++;
	}
	while ((l) && (*l))
	{
		*s = *l;
		l++;
		s++;
	}
	return ;
}
