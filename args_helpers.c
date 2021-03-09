/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:00:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/09 00:04:35 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	strict_char_set(const char *str, const char *set)
{
	const char	*rchar;
	const char	*rset;
	int			ok;

	rchar = str;
	rset = set;
	while (*rchar)
	{
		ok = 0;
		while (*rset)
		{
			if (*rset == *rchar)
			{
				ok = 1;
				break ;
			}
			rset++;
		}
		if (!ok)
			return (0);
		rchar++;
	}
	return (1);
}

int	strict_atoi(int *i_from_a, const char *argv)
{
	if (!(ft_check(argv, "[-+]?[0123456789]+$")))
		return (0);
	*i_from_a = ft_atoi(argv);
	return (1);
}
