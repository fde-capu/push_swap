/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/15 12:27:21 by fde-capu         ###   ########.fr       */
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
//	printf(">>count %d\n", k->result);
	return ;
}

char	*gen_push_swap(t_stk **a, t_stk **b)
{
	char	*o;

	o = ft_str("");
	chain_push_swap(a, b, &o);
	o = ft_x(o, ft_strtrim(o, ","));
//	stack_double_log(*a, *b);
	return (o);

//	while (!(is_in_order(*a)))
//	{
//		while (!(is_in_order(*a)))
//		{
//			o = ft_strcatxl(o, \
//				gen_split_low_high(a, b, stack_tail(*a)->val));
//		}
////		printf(">GO>\n");
////		stack_double_log(*a, *b);
////		printf("out:--%s--\n", o);
//		get_put_dump(a, b, &o);
//	}
//	return (o);
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
		//stack_double_log(stack_a, stack_b);
		init_ps_strategy(&ps_strat);
		solve_push_swap(ps_strat, stack_a);
		//printf("---%s---", ps_strat->formula);
		give_it_to_stdout(ps_strat);
		//op_exec(ops, &stack_a, &stack_b);
		//ft_print_stdout("Final:\n\n");
		//stack_double_log(stack_a, stack_b);
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
