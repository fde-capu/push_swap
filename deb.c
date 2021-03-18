/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:55:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/18 11:56:10 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	deb_bol_(int i)
{
	if (!DEBUG)
		return ;
	if (i)
		ft_print_stdout("Yes.\n");
	else
		ft_print_stdout("No.\n");
	return ;
}

void	deb_(char *s)
{
	if (DEBUG)
		ft_print_stdout(s);
	return ;
}

void	deb_int_(int i)
{
	char	*num;

	if (!DEBUG)
		return ;
	num = ft_itoa(i);
	num = ft_strcatxr(" ", num);
	num = ft_strcatxl(num, " ");
	deb_(num);
	free (num);
	return ;
}
