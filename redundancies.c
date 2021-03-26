/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundancies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:26:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/26 16:11:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_command(char **h)
{
	if ((!**h) || !*h || !h)
		return ;
	while (**h)
	{
		if (**h == ',')
		{
			(*h)++;
			break ;
		}
		(*h)++;
	}
	return ;
}

char	**strip_sub_code(char *sub_code)
{
	char	**code;

	code = ft_split(sub_code, ',');
	*(code[1] + (ft_strlen(code[1]) - 1)) = 0;
	return (code);
}

int	remove_str(char **str, char *rem)
{
	char	*h;
	int		out;

	out = 0;
	h = *str;
	while (*h)
	{
		if (ft_strbegins(h, rem))
		{
			*h = 0;
			if (*(h + ft_strlen(rem)))
			{
				h += ft_strlen(rem) + 1;
				*str = ft_strcatxl(*str, h);
			}
			h = *str;
			out++;
			deb_(rem);
			deb_("|");
		}
		next_command(&h);
	}
	return (out);
}

int	check_nested(char *h, char *sub_code, char **end)
{
	char	**code;
	int		c_up;
	int		c_mid;
	int		c_dn;

	code = strip_sub_code(sub_code);
	c_up = 0;
	c_mid = 0;
	c_dn = 0;
	while (ft_strbegins(h, code[0]))
	{
		next_command(&h);
		c_up++;
	}
	if (!c_up)
	{
		ft_strfree2d(code);
		return (0);
	}
	while (ft_strbegins(h, code[1]))
	{
		next_command(&h);
		c_mid++;
	}
	while (ft_strbegins(h, code[2]) && c_up > c_dn)
	{
		next_command(&h);
		c_dn++;
	}
	if (!c_dn || c_up > c_dn)
	{
		ft_strfree2d(code);
		return (0);
	}
	*end = h;
	ft_strfree2d(code);
	return (c_mid + c_up);
}

char	*gen_repetition(char *sub_code, int rep_count)
{
	char	*out;
	char	*op;
	char	**code;

	code = strip_sub_code(sub_code);
	op = ft_str(code[1]);
	ft_strfree2d(code);
	out = ft_str("");
	while (rep_count--)
	{
		out = ft_strcatxl(out, op);
		out = ft_strcatxl(out, ",");
	}
	free(op);
	return (out);
}

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
			deb_(sub_code);
			deb_("|");
			rep_str = gen_repetition(sub_code, rep_count);
			out = ft_str(end);
			out = ft_strcatxx(rep_str, out);
			*h = 0;
			*str = ft_strcatxx(*str, out);
			h = *str;
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
			deb_(sub_code);
			deb_("|");
			cue = h + ft_strlen(sub[0]);
			final_part = ft_strcat(sub[1], cue);
			*h = 0;
			*str = ft_strcatxx(*str, final_part);
			h = *str;
			out++;
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

	deb_("treat_redundancies:\n\n");
	deb_(strat->formula);
	deb_("\n\n");
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
	deb_("\n\n");
	deb_(strat->formula);
	deb_("\n\n");
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
