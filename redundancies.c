/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundancies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:26:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 09:27:23 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	recursive_redundancy(char **str, char *sub_code)
{
	int		rep_count;
	char	*out;
	char	*end;
	char	*rep_str;
	char	*h;

	h = *str;
	while (*h)
	{
		rep_count = check_nested(h, sub_code, &end);
		if (rep_count)
		{
			rep_str = gen_repetition(sub_code, rep_count);
			out = ft_str(end);
			out = ft_strcatxx(rep_str, out);
			*h = 0;
			*str = ft_strcatxx(*str, out);
			h = *str;
			deb_(sub_code);
			deb_(" ");
		}
		else
			next_command(&h);
	}
	return (0);
}

int	substitute_redundancy(char **str, char *sub_code)
{
	char	*h;
	char	*cue;
	char	**sub;
	char	*final_part;
	int		out;

	out = 0;
	sub = ft_split(sub_code, '>');
	h = *str;
	while (1)
	{
		if (!*h)
			break ;
		if (ft_strbegins(h, sub[0]))
		{
			cue = h + ft_strlen(sub[0]);
			final_part = ft_strcat(sub[1], cue);
			*h = 0;
			*str = ft_strcatxx(*str, final_part);
			h = *str;
			out++;
			deb_(sub_code);
			deb_(" ");
		}
		next_command(&h);
	}
	ft_strfree2d(sub);
	return (out);
}

int		treat_redundancies(t_ttg *strat)
{
	char	**red;
	int		i;
	int		count;

	deb_("treat_redundancies (");
	deb_(strat->formula);
	deb_(") ");
	count = 0;
	red = ft_split(REDUNDANCIES, '|');
	i = ft_strlen2d(red);
	while (i--)
	{
		if (ft_strstr(">", red[i]))
		{
			count += substitute_redundancy(&strat->formula, red[i]);
			continue ;
		}
		if (ft_strstr("*", red[i]))
		{
			count += recursive_redundancy(&strat->formula, red[i]);
			continue ;
		}
		count += remove_str(&strat->formula, red[i]);
	}
	ft_strfree2d(red);
	return (count);
}

void	solve_push_swap(t_ttg *k, t_stk *a)
{
	k->a = stack_clone(a);
	k->b = init_stack_empty();
	k->formula = (k->function)(&k->a, &k->b);
	treat_redundancies(k);
	k->result = count_instructions_in_str(k->formula);
	return ;
}
