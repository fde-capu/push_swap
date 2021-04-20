/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex_h1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:52:06 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/19 22:10:15 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rgx_mm_mod(int *mm, int oblig, int optio)
{
	*mm = oblig;
	*(mm + 1) = optio;
	return ;
}

int	rgx_mm_manual(int pos, char *keys)
{
	char	*h;

	if (pos == 0)
		return (ft_atoi(keys + 1));
	if (pos == 1)
	{
		h = ft_findstr(keys, ',');
		if (h)
			return (ft_atoi(h + 1));
		else
			return (rgx_mm_manual(0, keys));
	}
	return (1);
}

char	*rgx_sk_mod(char *mod)
{
	if ((!mod) || (!*mod))
		return (0);
	if (ft_chrinset(*mod, "+?*"))
		return (mod + 1);
	if (ft_chrinset(*mod, "{"))
		return (ft_inskip(mod));
	return (mod);
}

void	rgx_set_rep(int *mm, char *mod)
{
	rgx_mm_mod(&mm[0], 1, 1);
	if ((!mod) || (!(*mod)))
		return ;
	if (*mod == '+')
		rgx_mm_mod(&mm[0], 1, 0);
	if (*mod == '?')
		rgx_mm_mod(&mm[0], 0, 1);
	if (*mod == '*')
		rgx_mm_mod(&mm[0], 0, 0);
	if (*mod == '{')
		rgx_mm_mod(&mm[0], rgx_mm_manual(0, mod), rgx_mm_manual(1, mod));
	mm[1] -= (mm[0] - 1);
	if (mm[0] == 0 && mm[1] == 1)
		mm[1] = 0;
	return ;
}
