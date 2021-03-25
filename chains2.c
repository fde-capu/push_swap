/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chains2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:57:46 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/25 11:16:58 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			may_bubble_abo_nx(t_abo abo, int dir)
{
	if (dir == ATOB && (!abo.a || !(*abo.a)->nx))
		return (0);
	if (dir == BTOA && (!abo.b || !(*abo.b)->nx))
		return (0);
	if (dir == ATOB && (*abo.a)->nx->val > (*abo.a)->nx->nx->val)
			return (1);
	if (dir == BTOA && (*abo.b)->nx->val < (*abo.b)->nx->nx->val)
			return (1);
	return (0);
}

int			may_bubble_abo(t_abo abo, int dir)
{
	if (dir == ATOB && (!(*abo.a)->nx || !(*abo.a)->nx->nx))
		return (0);
	if (dir == BTOA && (!(*abo.b)->nx || !(*abo.b)->nx->nx))
		return (0);
	if (dir == ATOB && (*abo.a)->val > (*abo.a)->nx->val)
			return (1);
	if (dir == BTOA && (*abo.b)->val < (*abo.b)->nx->val)
			return (1);
	return (0);
}

void	shortest_rotation_dir_pivot(t_abo abo, int dir, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;
	t_stk	**a;
	t_stk	**b;

	if (dir == ATOB)
	{
		a = abo.a;
		b = abo.b;
	}
	if (dir == BTOA) // may fail for inverse positioning b
	{
		a = abo.b;
		b = abo.a;
	}
	if ((*a)->val <= pivot)
		return ;
	dist_dn = 0;
	h = *a;
	while (h && h->val > pivot && dist_dn++)
		h = h->nx;
	dist_up = 1;
	h = stack_tail(*a);
	while (h && h->val > pivot && dist_up++)
		h = h->pv;
	if (dist_dn < dist_up)
	{
		while (dist_dn--)
			ouch_abo(abo, dir, "r_");
	}
	else
	{
		while (dist_up--)
			ouch_abo(abo, dir, "rr_");
	}
	return ;
}

void	shortest_rotation_dir_receive(t_abo abo, int dir)
{
	if (dir == ATOB)
		shortest_rotation_b_receive(abo.a, abo.b, abo.o);
	if (dir == BTOA)
		shortest_rotation_a_receive(abo.a, abo.b, abo.o);
	return ;
}

void			ps_combo_nrewind(t_abo abo, int dir, int n)
{
	deb_("Combo'N Rewind!\n");
	deb_int_(n);
	while (n--)
	{
		deb_int_(n);
		shortest_rotation_dir_receive(abo, dir);
		ouch_abo(abo, pointer(dir), "p_");
	}
	return ;
}

int				qs_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	deb_("QS Combo Rewind!\n");
	while (stack_size(*b) > 0)
	{
		ps_try_bubble(a, b, o);
		shortest_rotation_b_flush(a, b, o);
		shortest_rotation_a_receive(a, b, o);
		ouch(a, b, o, "pa");
	}
	shortest_rotation_a_flush(a, b, o);
	return (estas_finita(*a, *b));
}

void	gen_pivot_dir_short(t_abo abo, int dir, int len, int *pivot)
{
	t_stk	*s;

	deb_("gen_pivot_dir_short ");
	if (dir == ATOB)
		s = stack_nclone(*abo.a, len);
	else
		s = stack_nclone(*abo.b, len);
	gen_pivot_short(&s, pivot);
	destroy_stack(s);
	return ;
}

void	gen_pivot_qs(t_abo abo, int dir, int len, int *pivot)
{
	t_stk	*s;

	deb_("gen_pivot_qs ");
	if (dir == ATOB)
		s = stack_nclone(*abo.a, len);
	else
		s = stack_nclone(*abo.b, len);
	gen_pivot_median(&s, pivot);
	destroy_stack(s);
	return ;
}

char	*op_(char *mask, int dir)
{
	char	*o;
	char	*h;

	o = ft_str(mask);
	h = o;
	while (*h)
	{
		if (*h == '_')
		{
			if (dir == ATOB)
				*h = 'a';
			if (dir == BTOA)
				*h = 'b';
		}
		h++;
	}
	return (o);
}

void	ouch_abo(t_abo abo, int dir, char *mask)
{
	char	*op;

	op = op_(mask, dir);
	ouch(abo.a, abo.b, abo.o, op);
	free (op);
	return ;
}

int		pointer(int dir)
{
	if (dir == ATOB)
		return (BTOA);
	if (dir == BTOA)
		return (ATOB);
	return (-1);
}

t_stk	*ab_destiny(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (*abo.b);
	if (dir == BTOA)
		return (*abo.a);
	return (0);
}

t_stk	*ab_origin(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (*abo.a);
	if (dir == BTOA)
		return (*abo.b);
	return (0);
}

int		pass_pivot(t_abo abo, int dir, int len, int pivot)
{
	t_stk	*h;
	int		o;

	deb_("pass_pivot...\n");
	o = 0;
	h = ab_origin(abo, dir);
	while (len && h)
	{
		if (ps_flush_ready(abo.a, abo.b, abo.o))
		{
			ps_combo_rewind(abo.a, abo.b, abo.o);
			break ;
		}
		h = ab_origin(abo, dir);
		if ((dir == ATOB && h->val <= pivot)
		|| (dir == BTOA && h->val > pivot))
		{
			shortest_rotation_dir_receive(abo, dir);
			ouch_abo(abo, pointer(dir), "p_");
			o++;
		}
		else
		{
			ouch_abo(abo, dir, "r_");
		}
		len--;
		if (len >= 2 && may_bubble_abo(abo, dir))
			ouch_abo(abo, dir, "s_");
		if (o && !(o % 2) && may_bubble_abo(abo, pointer(dir)))
			ouch_abo(abo, pointer(dir), "s_");
	}
	deb_("...end pass_pivot.\n");
	return (o);
}

void	pass_rn(t_abo abo, int dir, int n, int len)
{
	t_stk	*h;

	deb_("pass_rn");
	deb_("\n");
	h = ab_origin(abo, pointer(dir));
	len -= n;
	if (stack_size(h) != len)
		while (len--)
			ouch_abo(abo, pointer(dir), "rr_");
	while (n--)
		ouch_abo(abo, pointer(dir), "p_");
	return ;
}

void	pass_insertion(t_abo abo, int dir, int n, int len)
{
	deb_("pass_insertion :: ");
	ps_combo_nrewind(abo, dir, n);
	(void)len;
	return ;
}

void	offset(t_abo abo, int dir, int ofs)
{
	char	*op;

	if (!ofs)
		return ;
	deb_("offset");
	deb_int_(ofs);
	deb_("\n");
	if (ofs > 0)
		op = op_("r_", dir);
	else
		op = op_("rr_", dir);
	while (ofs)
	{
		ouch(abo.a, abo.b, abo.o, op);
		if (ofs > 0)
			ofs--;
		else
			ofs++;
	}
	free(op);
	return ;
}

int		in_order_len(t_abo abo, int dir, int len)
{
	t_stk	*h;

	h = ab_origin(abo, dir);
	while (--len)
	{
		if (dir == ATOB && h->nx->val < h->val)
			return (0);
		if (dir == BTOA && h->nx->val > h->val)
			return (0);
		h = h->nx;
	}
	return (1);
}

int		dir_asc_desc(int dir)
{
	if (dir == ATOB)
		return (ASCE);
	if (dir == BTOA)
		return (DESC);
	return (-2);
}

void	bubble3(t_abo abo, int dir, int len)
{
	deb_("bubble3\n");
	if (len <= 1 || in_order_len(abo, dir, len))
		return ;
	if (may_bubble_abo(abo, dir))
	{
		ouch_abo(abo, dir, "s_");
		if (in_order_len(abo, dir, len))
			return ;
	}
	if (len == 2)
		return ;
	if (may_bubble_abo_nx(abo, dir))
	{
		ouch_abo(abo, dir, "r_");
		ouch_abo(abo, dir, "s_");
		ouch_abo(abo, dir, "rr_");
		if (may_bubble_abo(abo, dir))
			ouch_abo(abo, dir, "s_");
	}
	return ;
}

void	partition(t_abo abo, int dir, int ofs, int len)
{
	static int	pivot = 0;
	int			passed;
	static int	deb = 0; if (deb++>10) exit (0);

//	offset(abo, dir, ofs);
	if (estas_finita(*abo.a, *abo.b))
		return ;
	if (len <= 3)
	{
		bubble3(abo, dir, len);
		return ;
	}
	deb_("partition");
	deb_int_(len);
	deb_("\n");
	gen_pivot_qs(abo, dir, len, &pivot);
	passed = pass_pivot(abo, dir, len, pivot);
	if (len - passed > 3)
	{
		deb_("repart origin ");
		partition(abo, dir, 0, len - passed);
	}
	if (passed >= 3)
	{
		deb_("repart passed ");
		partition(abo, pointer(dir), 0, passed);
	}
	pass_insertion(abo, pointer(dir), passed, len);
//	pass_rn(abo, pointer(dir), passed, len);
	offset(abo, dir, ofs * -1);
	deb_("\n\n");
	return ;
}

void	quick_sort(t_stk **a, t_stk **b, char **o)
{
	t_abo	abo;

	deb_("sort\n");
	abo.a = a;
	abo.b = b;
	abo.o = o;
	partition(abo, ATOB, 0, stack_size(*a));
	ps_combo_rewind(a, b, o);
	return ;
}
