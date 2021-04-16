/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:17:20 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/16 13:56:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			validate_op(char *op)
{
	if (ft_check(op, " "))
		return (0);
	if (ft_strstr(op, OP_NAMES) && !(ft_chrinset(' ', op)))
		return (1);
	return (0);
}

int			xxret(char *a, char *b, int ret)
{
	free(a);
	free(b);
	return (ret);
}

int			validate_stdin_ops(char ***ops)
{
	char	*line;
	char	*ops_stream;

	ops_stream = 0;
	line = 0;
	while (get_next_line(0, &line))
	{
		if (!(validate_op(line)))
		{
			return (xxret(line, ops_stream, 0));
		}
		if (ops_stream)
		{
			ops_stream = ft_strcatxl(ops_stream, ",");
			ops_stream = ft_strcatxl(ops_stream, line);
		}
		else
			ops_stream = ft_str(line);
		free(line);
	}
	if (!ops_stream)
		return (xxret(line, ops_stream, 1));
	*ops = ft_split(ops_stream, ',');
	return (xxret(line, ops_stream, 1));
}
