/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:09:37 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/22 14:11:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define DEBUG		0
# define OP_NAMES	"sa sb ss pa pb ra rb rr rra rrb rrr"
# define REDUNDANCIES	"ra,rra|rra,ra|rb,rrb|rrb,rb|pb,pa|pa,pb|sa,pb,ra>ra,pb|sb,pa,rb>rb,pa|rrr,rb>ra|rrr,ra>rb|ra,sa,rb>rr,sa|rb,sb,ra>rr,sb|ra,rr*,rb|rb,rr*,ra|rra,rrr*,rrb|rrb,rrr*,rra"

# define ER	-1
# define OK	0
# define KO	1

# define FUN_DIG		1
# define FUN_PAR		2
# define FUN_SET		3
# define FUN_CHR		4
# define ENCLOSURES		"()[]{}"
# define ENCLOSE_OPEN	"([{"
# define TRIM_SET		" \t\n\r\v\f"

typedef struct			s_tack
{
	int					val;
	struct s_tack		*nx;
	struct s_tack		*pv;
}						t_stk, t_stack_buffer;

typedef struct			s_trategy
{
	char				*(*function)(t_stk **a, t_stk **b);
	char				*formula;
	int					result;
	t_stack_buffer		*a;
	t_stack_buffer		*b;
}						t_ttg;

#endif
