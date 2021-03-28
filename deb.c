/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:55:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/27 21:00:49 by fde-capu         ###   ########.fr       */
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
		ft_print_stdout((const char *)s);
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

void			deb_pivot(int val)
{
	if (!DEBUG)
		return ;
	ft_print_stdout("New pivot: ");
	ft_print_int(val);
	ft_print_stdout(".\n");
//	sleep(1);
	return ;
}

void			deb_stack_double_log(t_stk *a, t_stk *b)
{
	if (DEBUG)
		stack_double_log(a, b);
	return ;
}
