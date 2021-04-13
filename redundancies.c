/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redundancies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:26:17 by fde-capu          #+#    #+#             */
/*   Updated: 2021/04/13 15:39:34 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		recursive_redundancy(char **str, char *sub_code)
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

void	substitute_redundancy(char **str, char *sub_code)
{
	char	*h;
	char	*cue;
	char	**sub;
	char	*final_part;

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
		}
		next_command(&h);
	}
	ft_strfree2d(sub);
	return ;
}

char	**gen_red(void)
{
	char	**red;
	char	*b;
	
	b = ft_str("ra,rra|rra,ra|rb,rrb|rrb,rb|pb,pa|pa,pb|sa,pb,ra>ra,pb|");
	b = ft_strcatxl(b, "sb,pa,rb>rb,pa|rrr,rb>ra|rrr,ra>rb|");
	b = ft_strcatxl(b, "ra,sa,rb>rr,sa|rb,sb,ra>rr,sb|ra,rr*,rb|rb,rr*,ra|");
	b = ft_strcatxl(b, "rra,rrr*,rrb|rrb,rrr*,rra|ra,pb,rra,pa>sa|");
	b = ft_strcatxl(b, "rb,pa,rrb,pb>sb|sa,sb>ss|sb,sa>ss|");
	b = ft_strcatxl(b, "sa,pb,sa,pb>ra,pb,pb,rra|sb,pa,sb,pa>rb,pa,pa,rrb|");
	b = ft_strcatxl(b, "pb,ra,pa>sa,ra|pa,rb,pb>sb,rb|sa,ra,pb>pb,ra|");
	b = ft_strcatxl(b, "sb,rb,pa>pa,rb");
	red = ft_split(b, '|');
	free(b);
	return (red);
}

void	treat_redundancies(t_ttg *strat)
{
	char	**red;
	int		i;

	red = gen_red();
	i = ft_strlen2d(red);
	while (i--)
	{
		if (ft_strstr(">", red[i]))
		{
			substitute_redundancy(&strat->formula, red[i]);
			continue ;
		}
		if (ft_strstr("*", red[i]))
		{
			recursive_redundancy(&strat->formula, red[i]);
			continue ;
		}
		remove_str(&strat->formula, red[i]);
	}
	ft_strfree2d(red);
	return ;
}
