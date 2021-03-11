/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 03:12:02 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 23:39:47 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	*ft_strdup(const char *str)
{
	char	*new;

	new = ft_calloc(ft_strlen(str) + 1, 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, str);
	return (new);
}

char	*ft_strnew(void)
{
	return (ft_strdup(""));
}

char	*ft_str(char *str)
{
	return (ft_strdup(str));
}

char	*ft_strx(char *s1, char *s2)
{
	return (ft_x(s2, ft_strdup(s1)));
}
