/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/18 11:55:16 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ttg	**init_ps_strategy(t_ttg **k)
{
	(*k) = ft_calloc(sizeof(t_ttg), 1);
	(*k)->function = gen_push_swap;
	return (k);
}

void	solve_push_swap(t_ttg *k, t_stk *a)
{
	k->a = stack_clone(a);
	k->b = init_stack_empty();
	k->formula = (k->function)(&k->a, &k->b);
	k->result = count_instructions_in_str(k->formula);
	return ;
}

char	*gen_push_swap(t_stk **a, t_stk **b)
{
	char	*o;

	o = ft_str("");
	chain_push_swap(a, b, &o);
	o = ft_x(o, ft_strtrim(o, ","));
	return (o);
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
