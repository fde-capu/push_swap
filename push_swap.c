/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/16 13:14:02 by fde-capu         ###   ########.fr       */
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
		stack_double_log(stack_a, stack_b);
		init_ps_strategy(&ps_strat);
		solve_push_swap(ps_strat, stack_a);
		//printf("---%s---", ps_strat->formula);
		give_it_to_stdout(ps_strat);
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

t_stk		*cell_by_val(t_stk *s, int control)
{
	while (s)
	{
		if (s->val == control)
			return (s);
		s = s->nx;
	}
	return (0);
}

int			min_val(t_stk *ss)
{
	int		control;
	t_stk	*s;

	s = ss;
	control = s->val;
	while (s)
	{
		if (s->val < control)
			control = s->val;
		s = s->nx;
	}
	return (control);
}

int			max_val(t_stk *ss)
{
	int		control;
	t_stk	*s;

	s = ss;
	control = s->val;
	while (s)
	{
		if (s->val > control)
			control = s->val;
		s = s->nx;
	}
	return (control);
}

t_stk		*min_cell(t_stk *ss)
{
	int		control;

	control = min_val(ss);
	return (cell_by_val(ss, control));
}

t_stk		*max_cell(t_stk *ss)
{
	int		control;

	control = max_val(ss);
	return (cell_by_val(ss, control));
}

int				in_order_out_of_rot(t_stk *a)
{
	printf("check inorderout\n");
	int		loop;
	t_stk	*h;
	int		prev;

	loop = stack_size(a);
	h = min_cell(a);
	while (loop--)
	{
		prev = h->val;
		h = h->nx;
		if (!h)
			h = a;
		printf("hval %d orev %d\n", h->val, prev);
		if ((h->val < prev) && (h != min_cell(a)))
			return (0);
	}
	return (1);
}

int				in_reverse_out_of_rot(t_stk *a)
{
	printf("check reverseout\n");
	int		loop;
	t_stk	*h;
	int		prev;

	loop = stack_size(a);
	h = max_cell(a);
	while (loop--)
	{
		prev = h->val;
		h = h->nx;
		if (!h)
			h = a;
		if ((h->val > prev) && (h != max_cell(a)))
			return (0);
	}
	return (1);
}
