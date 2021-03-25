/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 09:27:27 by fde-capu         ###   ########.fr       */
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
			deb_("x(");
			deb_(rem);
			deb_(") ");
		}
		next_command(&h);
	}
	return (out);
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

t_stk	*filter_le(t_stk *s, int control)
{
	t_stk	*xa;
	t_stk	*xb;

	xa = stack_clone(s);
	xb = init_stack_empty();
	while (count_gt(xa, control))
	{
		if (xa->val > control)
			op_run_str("pb", &xa, &xb);
		else
			op_run_str("ra", &xa, &xb);
	}
	destroy_stack(xb);
	return (xa);
}
