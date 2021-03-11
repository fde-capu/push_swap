/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:13:45 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 23:40:14 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	ft_print_stdout(const char *str)
{
	write(1, str, ft_strlen(str));
	return ;
}

void	ft_print_x(char *str)
{
	ft_print_stdout((const char *)str);
	free(str);
	return ;
}
