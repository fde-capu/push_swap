/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:55:36 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 14:48:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		deb_bol_(int i)
{
	if (DEBUG != 1)
		return (i);
	if (i)
		ft_print_stdout("Yes.\n");
	else
		ft_print_stdout("No.\n");
	return (i);
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

	if (DEBUG == 0)
		return ;
	num = ft_itoa(i);
	num = ft_strcatxr(" ", num);
	num = ft_strcatxl(num, " ");
	deb_(num);
	free(num);
	return ;
}

void	deb_stack_double_log(t_stk *a, t_stk *b)
{
	if (DEBUG)
		stack_double_log(a, b);
	return ;
}

void	deb_abo(t_abo abo)
{
	deb_stack_double_log(*abo.a, *abo.b);
	return ;
}
