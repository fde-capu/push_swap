/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundancies2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:26:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 21:04:42 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**strip_sub_code(char *sub_code)
{
	char	**code;

	code = ft_split(sub_code, ',');
	*(code[1] + (ft_strlen(code[1]) - 1)) = 0;
	return (code);
}

int	remove_str(char **str, char *rem)
{
	char	*h;
	int		out;

	out = 0;
	h = *str;
	while (*h)
	{
		if (ft_strbegins(h, rem))
		{
			*h = 0;
			if (*(h + ft_strlen(rem)))
			{
				h += ft_strlen(rem) + 1;
				*str = ft_strcatxl(*str, h);
			}
			h = *str;
			out++;
			deb_(rem);
			deb_("|");
		}
		next_command(&h);
	}
	return (out);
}

int	free_str2d_and_return(char **str, int ret)
{
	ft_strfree2d(str);
	return (ret);
}

void	next_command_and_up(char **h, int *v)
{
	next_command(h);
	*v += 1;
	return ;
}

int	check_nested(char *h, char *sub_code, char **end)
{
	char	**code;
	int		c_up;
	int		c_mid;
	int		c_dn;

	code = strip_sub_code(sub_code);
	c_up = 0;
	c_mid = 0;
	c_dn = 0;
	while (ft_strbegins(h, code[0]))
		next_command_and_up(&h, &c_up);
	if (!c_up)
		return (free_str2d_and_return(code, 0));
	while (ft_strbegins(h, code[1]))
	{
		next_command(&h);
		c_mid++;
	}
	while (ft_strbegins(h, code[2]) && c_up > c_dn)
		next_command_and_up(&h, &c_dn);
	if (!c_dn || c_up > c_dn)
		return (free_str2d_and_return(code, 0));
	*end = h;
	ft_strfree2d(code);
	return (c_mid + c_up);
}
