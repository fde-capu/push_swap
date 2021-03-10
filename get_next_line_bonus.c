/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:48:01 by fde-capu          #+#    #+#             */
/*   Updated: 2020/05/14 18:45:28 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clear(char *s)
{
	int	x;

	x = 0;
	while (x < BUFFER_SIZE)
	{
		*(s + x) = 0;
		x++;
	}
	return ;
}

int		get_next_line(int fd, char **line)
{
	static char	save[256][BUFFER_SIZE + 1];
	int			r;
	char		tmp[BUFFER_SIZE + 1];
	char		*buf;

	if ((!line) || BUFFER_SIZE == 0)
		return (-1);
	*line = concat(NULL, save[fd]);
	r = 1;
	while ((r) && (!findnl(*line)))
	{
		buf = tmp;
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			*line = NULL;
			return (r);
		}
		tmp[r] = 0;
		*line = concat(*line, tmp);
	}
	clear(save[fd]);
	dosave(*line, save[fd]);
	return (r ? 1 : 0);
}
