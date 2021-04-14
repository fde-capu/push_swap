/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_string_ops.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:52:13 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/14 13:06:24 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_command(char **h)
{
	if ((!**h) || !*h || !h)
		return ;
	while (**h)
	{
		if (**h == ',')
		{
			(*h)++;
			break ;
		}
		(*h)++;
	}
	return ;
}

char	*prev_command(char **h, char *limit)
{
	char	*c;

	c = *h;
	if (c <= limit + 2)
	{
		*h = limit;
		return (limit);
	}
	if (*(c - 1) == ',')
		c -= 2;
	while (*c != ',' && c > limit)
		c--;
	if (c > limit)
		c++;
	*h = c;
	return (*h);
}
