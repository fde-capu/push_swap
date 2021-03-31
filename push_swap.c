/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:07 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/31 09:11:08 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_1_(t_abo loc, int bub)
{
	if (bub)
		bubble(loc);
	shortest_rotation_a_receive(loc);
	return ;
}

void	s_2_(t_abo loc, int bub)
{
	if (bub)
		bubble(loc);
	flush_b(loc);
	shortest_rotation_a_receive(loc);
	return ;
}

void	s_3_(t_abo loc, int bub)
{
	if (bub)
		bubble(loc);
	flush_b(loc);
	flush_a(loc);
	shortest_rotation_a_receive(loc);
	return ;
}

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

void	give_it_to_stdout(t_ttg *s)
{
	char	*h;

	if (DEBUG)
	{
		deb_int_(s->result);
		return ;
	}
	if (!(s->formula))
		return ;
	h = s->formula;
	while (*h)
	{
		if (*h == ',')
			write(1, "\n", 1);
		else
			write(1, h, 1);
		h++;
	}
	if (h != s->formula)
		write(1, "\n", 1);
	return ;
}


/*
** k->function leads here:
** push_swap_sort resides in chains.c.
*/

void			chain_push_swap(t_stk **a, t_stk **b, char **o)
{
	push_swap_sort(a, b, o);
	return ;
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
		deb_("\nInitial:\n\n");
		deb_stack_double_log(stack_a, stack_b);
		init_ps_strategy(&ps_strat);
		solve_push_swap(ps_strat, stack_a);
		give_it_to_stdout(ps_strat);
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
	if (DEBUG == 1)
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
