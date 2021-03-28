
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

void	gen_pivot_dir_chunk_by_median(t_abo abo, int dir, int chunk, int *pivot)
{
	t_stk	*tmp;
	int		size;

	deb_("gen_pivot_dir_chunk (median) ");
	if (dir == ATOB)
		tmp = stack_clone(*abo.a);
	if (dir == BTOA)
		tmp = stack_clone(*abo.b);
	size = stack_size(tmp);
	while (size > chunk && size > 2)
	{
		deb_int_(size);
		deb_("|");
		tmp = stack_x(tmp, filter_le(tmp, stack_median(tmp)->val));
		size = stack_size(tmp);
	}
	*pivot = stack_median(tmp)->val;
	destroy_stack(tmp);
	deb_int_(size);
	deb_("\n");
	deb_pivot(*pivot);
	return ;
}

int		gen_chunk_size(t_abo abo, int dir)
{
	t_stk	*tmp;
	int		size;

	deb_("gen_chunk_size");
	if (dir == ATOB)
		tmp = stack_clone(*abo.a);
	if (dir == BTOA)
		tmp = stack_clone(*abo.b);
	size = stack_size(tmp);
	if (size <= 4)
		size = 5;
	else if (size <= 5)
		size = 5;
	else if (size <= 10)
		size = 6;
	else if (size <= 20)
		size = 13;
	else if (size <= 100)
		size = 52;
	else if (size <= 500)
		size = 127;
	else
		size = 200;
	destroy_stack(tmp);
	deb_int_(size);
	deb_(": ");
	return (size);
}

void	gen_pivot_dir_chunk(t_abo abo, int dir, int chunk, int *pivot)
{
	t_stk	*tmp;

	deb_("gen_pivot_dir_chunk (gross) size:");
	if (dir == ATOB)
		tmp = stack_nclone(*abo.a, chunk);
	if (dir == BTOA)
		tmp = stack_nclone(*abo.b, chunk);
	*pivot = stack_median(tmp)->val;
	destroy_stack(tmp);
	deb_int_(stack_size(tmp));
	deb_(".\n");
	deb_pivot(*pivot);
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

int				ps_combo_rewind(t_stk **a, t_stk **b, char **o)
{
	deb_("Combo Rewind!\n");
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

int				lower_val(int a, int b)
{
	if (a <= b)
		return (a);
	if (b < a)
		return (b);
	return (0);
}

int				ps_flush_ready(t_stk **a, t_stk **b, char **o)
{
	(void)o;
	deb_("Flush_ready? ");
	if (in_order_out_of_rot(*a) && in_reverse_out_of_rot(*b))
	{
		deb_("Yes.\n");
		return (1);
	}
	deb_("No.\n");
	return (0);
}

int	ps_pb_le_pivot(t_stk **a, t_stk **b, char **o, int pivot)
{
	t_stk	*h;
	int		did;

	did = 0;
	h = *a;
	while (h->nx)
	{
		if (!(count_le(*a, pivot)))
			break ;
		deb_("Try pb");
		deb_int_(h->val);
		deb_("pivot");
		deb_int_(pivot);
		if (h->val <= pivot)
		{
			shortest_rotation_b_receive(a, b, o);
			did = ouch(a, b, o, "pb");
		}
		else
		{
			did = shortest_rotation_a_pivot(a, b, o, pivot);
		}
		if (ps_flush_ready(a, b, o))
			return (did);
		h = *a;
	}
	deb_("Partitioning finished.");
	return (did);
}



int				ps_try_bubble(t_stk **a, t_stk **b, char **o)
{
	int		oa;
	int		ob;

	deb_("Try bubble. ");
	oa = may_bubble(*a, ASCE);
	ob = may_bubble(*b, DESC);
	if (oa && ob)
		return (ouch(a, b, o, "ss"));
	if (oa)
		return (ouch(a, b, o, "sa"));
	if (ob)
		return (ouch(a, b, o, "sb"));
	deb_("No.\n");
	return (0);
}

int	bubble_and_flush(t_stk **a, t_stk **b, char **o)
{
	ps_try_bubble(a, b, o);
	return (ps_flush_ready(a, b, o));
}

int		count_le_len(t_stk *h, int about, int len)
{
	if (!h || !len)
		return (0);
	if (h->val <= about)
		return (count_le_len(h->nx, about + 1, --len));
	else
		return (count_le_len(h->nx, about, --len));
}


int		shortest_rotation_a_pivot(t_abo abo, int pivot)
{
	int	dist_up;
	int	dist_dn;
	t_stk	*h;

	if ((*a)->val <= pivot)
		return (0);
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
			ouch(a, b, o, "ra");
	}
	else
	{
		while (dist_up--)
			ouch(a, b, o, "rra");
	}
	return (1);
}

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

int				reverse(int dir)
{
	return (pointer(dir));
}

int			may_bubble_abo(t_abo abo, int dir)
{
	if (dir == ATOB)
		return (may_bubble(*abo.a, ASCE));
	if (dir == BTOA)
		return (may_bubble(*abo.b, DESC));
	return (0);
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


int		pointer(int dir)
{
	if (dir == ATOB)
		return (BTOA);
	if (dir == BTOA)
		return (ATOB);
	return (-1);
}

