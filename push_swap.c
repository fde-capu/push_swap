/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 14:25:21 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ttg	**init_ps_strategy(t_ttg **k)
{
	(*k) = ft_calloc(sizeof(t_ttg), 1);
	(*k)->function = gen_push_swap;
	return (k);
}

char	*gen_push_swap(t_stk **a, t_stk **b)
{
	char	*o;

	o = ft_str("");
	chain_push_swap(a, b, &o);
	o = ft_x(o, ft_strtrim(o, ","));
	return (o);
}

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

char	*find_on_ops(char *ops, char *find)
{
	char	*h;

	h = ops;
	while (*h && (!(ft_strbegins(h, find))))
	{
		next_command(&h);
	}
	if (!*h)
		return (0);
	return (h);
}

char	**strip_sub_code(char *sub_code)
{
	char	**code;

	code = ft_split(sub_code, ',');
	*(code[1] + (ft_strlen(code[1]) - 1)) = 0;
	return (code);
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
		}
		next_command(&h);
	}
	ft_strfree2d(sub);
	return (out);
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
			h += ft_strlen(rem) + 1;
			*str = ft_strcatxl(*str, h);
			h = *str;
			out++;
		}
		next_command(&h);
	}
	return (out);
}

int		treat_redundancies(t_ttg *strat)
{
	char	**red;
	int		i;
	int		count;

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
//	if (count)
//		treat_redundancies(strat);
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

int			main(int argc, char **argv)
{
	t_stk	*stack_a;
	t_stk	*stack_b;
	char	**ops;
	t_ttg	*ps_strat;

	ops = 0;
	if (validate_args(argc, argv))
	{
		stack_a = init_stack_from_args(argc, argv);
		stack_b = init_stack_empty();
		//ft_print_stdout("\nInitial:\n\n");
		deb_stack_double_log(stack_a, stack_b);
		init_ps_strategy(&ps_strat);
		solve_push_swap(ps_strat, stack_a);
		give_it_to_stdout(ps_strat);
		deb_int_(ps_strat->result);
		//op_exec(ops, &stack_a, &stack_b);
		//ft_print_stdout("Final:\n\n");
		//if (is_in_order(stack_a) && !(stack_size(stack_b)))
		//	exit(end_routine(stack_a, stack_b, ops, OK));
		//exit(end_routine(stack_a, stack_b, ops, KO));
		strategy_destroy(ps_strat);
		destroy_stack(stack_a);
		destroy_stack(stack_b);
		exit(0);
	}
	else
	{
		if (argc != 1)
			exit(error_out());
	}
	exit(0);
}

void	re_ouch(t_stk **a, t_stk **b, char **o, char *ops)
{
	char	**spl;
	int		spl_len;
	int		i;

	spl = ft_split(ops, ',');
	spl_len = ft_strlen2d(spl);
	i = 0;
	while (i < spl_len)
	{
		ouch(a, b, o, spl[i]); 
		i++;
	}
	ft_strfree2d(spl);
	return ;
}

char	*last_op(char **o)
{
	char *coma;
	char	*h;

	h = *o;
	while (*h)
	{
		if (*h == ',')
			coma = h;
		h++;
	}
	return (++coma);
}

int		op_undo(char **o)
{
	char	*last;

	last = last_op(o);
	*(last - 1) = 0;
	last = last_op(o);
	*(last - 1) = 0;
	return (0);
}

char	*penult_op(char **o)
{
	char *coma;
	char	*stop;
	char	*h;
	char	*out;

	h = *o;
	coma = h;
	while (*h)
	{
		if (*h == ',')
			coma = h;
		h++;
	}
	stop = coma;
	coma--;
	while (coma > *o && *coma != ',')
		coma--;
	if (coma == *o)
		return (ft_str(""));
	out = ft_calloc(sizeof(char) * (stop - coma), 1);
	h = out;
	coma++;
	while (*coma != ',')
	{
		*h = *coma;
		coma++;
		h++;
	}
	return (out);
}

int		is_redundant(char *op_before, char *op_after)
{
	char	*red_str;
	char	*out_check;
	int		out;

	if (!*op_before || !*op_after)
		return (0);
	red_str = ft_str(",");
	red_str = ft_strcatxl(red_str, op_before);
	red_str = ft_strcatxl(red_str, ">");
	red_str = ft_strcatxl(red_str, op_after);
	red_str = ft_strcatxl(red_str, ",");
	out_check = ft_strstr(red_str, REDUNDANCIES);
	if (out_check)
		out = 1;
	else
		out = 0;
	free(red_str);
	return (out);
}

int		op_redundant(char **o, char *op)
{
	char	*last;

	last = penult_op(o);
	deb_("Redundant? (");
	deb_(last);
	deb_("->");
	deb_(op);
	deb_("). ");
	if (is_redundant(last, op))
	{
		free(last);
		deb_("Yes.\n");
		return (1);
	}
	free(last);
	deb_("No.\n");
	return (0);
}

int		ouch(t_stk **a, t_stk **b, char **o, char *op)
{
	*o = ft_strcatxl(*o, ",");
	*o = ft_strcatxl(*o, op);
	op_run_str(op, a, b);
	if (DEBUG)
	{
		ft_print_stdout(op);
		ft_print_stdout(":\n");
		stack_double_log(*a, *b);
	}
	return (1);
}
