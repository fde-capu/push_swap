/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:10:38 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:31:57 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	ft_ternary_i(int x, int vt, int vf)
{
	if (x)
		return (vt);
	return (vf);
}

char	*ft_ternary_c(int x, char *vt, char *vf)
{
	if (x)
		return (vt);
	return (vf);
}

long long	freec_and_retll(char *f, long long r)
{
	free (f);
	return (r);
}
