/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:24:19 by fde-capu          #+#    #+#             */
/*   Updated: 2021/03/08 23:40:39 by fde-capu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	strict_char_set(const char *str, const char *set)
{
	const char	*rchar;
	const char	*rset;
	int			ok;

	rchar = str;
	rset = set;
	while (*rchar)
	{
		ok = 0;
		while (*rset)
		{
			if (*rset == *rchar)
			{
				ok = 1;
				break;
			}
			rset++;
		}
		if (!ok)
			return (0);
		rchar++;
	}
	return (1);
}

int	strict_atoi(int *i_from_a, const char *argv)
{
	if (!(ft_check(argv, "[-+]?[0123456789]+$")))
		return (0);
	*i_from_a = ft_atoi(argv);
	return (1);
}

int	init_arg(t_arg **arg_dst, char *argv)
{
	int	*i_from_a;

	i_from_a = malloc(sizeof(int));
	if (!(strict_atoi(i_from_a, argv)))
		return (0);
	*arg_dst = malloc(sizeof(t_arg));
	(*arg_dst)->val = 0;
	printf(">>this arg: %d.\n", *i_from_a);
	free(i_from_a);
	return (1);
}

int	validate_args(int argc, char **argv)
{
	t_arg	*arg_dst;
	int		arg_i;

	if (argc == 1)
		return (0);
	arg_i = 0;
	while (++arg_i < argc)
	{
		if (!(init_arg(&arg_dst, argv[arg_i])))
			return (0);
		free (arg_dst);
	}
	return (1);
}
