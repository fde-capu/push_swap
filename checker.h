/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:13:12 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/11 08:56:12 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

int			main(int argc, char **argv);
int			end_routine(t_stk *stack_a, t_stk *stack_b, char **ops, int out);
int			validate_op(char *op);
int			validate_stdin_ops(char ***ops);

#endif
