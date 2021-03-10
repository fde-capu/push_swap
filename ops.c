/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:39:18 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 14:58:40 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			validate_op(char *op)
{
	if (ft_check(op, " "))
		return (0);
	if (ft_strstr(op, OP_NAMES))
		return (1);
	return (0);
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
			free(line);
			free(ops_stream);
			return (0);
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
	free(line);
	if (!ops_stream)
	{
		free(ops_stream);
		return (0);
	}
	printf(">>>%s<<<\n", ops_stream);
	*ops = ft_split(ops_stream, ',');
	free(ops_stream);
	return (1);
}
