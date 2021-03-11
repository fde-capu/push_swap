/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:09:37 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/10 23:13:00 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# define OP_NAMES	"sa sb ss pa pb ra rb rr rra rrb rrr"

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

typedef struct			s_stack
{
	int					val;
	struct s_stack		*nx;
	struct s_stack		*pv;
}						t_stk;

#endif
