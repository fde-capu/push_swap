# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 16:20:12 by fde-capu          #+#    #+#              #
#    Updated: 2021/03/16 14:44:19 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/sh
ARGS_A_PRE	=	echo -e "sa\nsa" |
ARGS_A		=	2 1 0
ARGS_B		=	1 5 2 4 3
ARGS_C		=	9 10 -3 0 -115
NAME_A		=	checker
NAME_B		=	push_swap
SRCS_A		=	checker.c ops_check.c
SRCS_B		=	push_swap.c ps_strategy.c \
	generic_stack_ops.c chains.c
HEADS_A		=	checker.h
HEADS_B		=	push_swap.h
SRCS_COMMON	=	args.c ft_atoi.c ft_isdigit.c ft_strtrim.c \
	ft_calloc.c ft_bzero.c ft_chrinset.c ft_regex.c \
	ft_regex_h1.c ft_regex_h2.c ft_insplit.c ft_strnstr.c \
	ft_inskip.c ft_findstr.c ft_strlcpy.c ft_strlen.c \
	ft_strfree2d.c ft_substr.c args_helpers.c stack.c \
	ft_itoa.c ft_strcat.c ft_print.c ft_split.c ft_strdup.c \
	ft_xlloc.c ft_strcpy.c stack_init.c stack_ops.c \
	stack_logs.c ft_stridentical.c ops_s.c ops_p.c \
	ops_r.c ops_rr.c ft_atol.c get_next_line_bonus.c \
	get_next_line_utils_bonus.c stack_init_2.c
HEAD_COMMON	=	common.h defs.h get_next_line_bonus.h
CC			=	clang
CCFLAGS		=	-Wall -Werror -Wextra -g
OBJS_A		=	$(SRCS_A:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)
OBJS_COMMON	=	$(SRCS_COMMON:.c=.o)
VALGRIND	=	valgrind
VALGFLAGS	=	--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--show-reachable=yes

all:		$(NAME_A) $(NAME_B)
a:			$(NAME_A)
b:			$(NAME_B)

$(NAME_A):	$(OBJS_A) $(OBJS_COMMON)
	$(CC) $(CCFLAGS) $(OBJS_A) $(OBJS_COMMON) -o $(NAME_A)
$(NAME_B):	$(OBJS_B) $(OBJS_COMMON)
	$(CC) $(CCFLAGS) $(OBJS_B) $(OBJS_COMMON) -o $(NAME_B)
$(OBJS_A):	%.o : %.c $(HEADS_A)
	$(CC) $(CCFLAGS) -o $@ -c $<
$(OBJS_B):	%.o : %.c $(HEADS_B)
	$(CC) $(CCFLAGS) -o $@ -c $<
$(OBJS_COMMON):	%.o : %.c $(HEAD_COMMON)
	$(CC) $(CCFLAGS) -o $@ -c $<

fclean:		fcleana fcleanb
clean:		cleana cleanb
fcleana:	cleana
	-rm -f $(NAME_A)
fcleanb:	cleanb
	-rm -f $(NAME_B)
	-rm -f $(OBJS_COMMON)
cleana:
	-rm -f $(OBJS_A)
	-rm -f $(OBJS_COMMON)
cleanb:
	-rm -f $(OBJS_B)
rea:		fcleana $(NAME_A)
reb:		fcleanb $(NAME_B)
re:			fclean all
ta:			$(NAME_A)
	$(ARGS_A_PRE) ./$(NAME_A) $(ARGS_A)
tb:			$(NAME_B)
	./$(NAME_B) $(ARGS_A)
t:			ta tb
rta:		rea ta
rtb:		reb tb
rt:			re t
tt:			rt
vv:			re v
rv:			vv
va:			$(NAME_A)
	$(ARGS_A_PRE) $(VALGRIND) ./$(NAME_A) $(ARGS_A)
vb:			$(NAME_B)
	$(VALGRIND) ./$(NAME_B) $(ARGS_A)
v:			va vb
vva:		re va
rva: 		vva
vvb: 		re vb
rvb: 		vvb
vfa:		$(NAME_A)
	$(ARGS_A_PRE) $(VALGRIND) $(VALGFLAGS) ./$(NAME_A) $(ARGS_A)
vfb:		$(NAME_B)
	$(VALGRIND) $(VALGFLAGS) ./$(NAME_B) $(ARGS_A)
vf:			vfa vfb
tx:			all
	./$(NAME_B) $(ARGS_A) | ./$(NAME_A) $(ARGS_A)
tv:			all
	$(VALGRIND) ./$(NAME_B) $(ARGS_A) | $(VALGRIND) ./$(NAME_A) $(ARGS_A)
xa:			all
	./$(NAME_B) $(ARGS_A) | ./$(NAME_A) $(ARGS_A)
xb:			all
	./$(NAME_B) $(ARGS_B) | ./$(NAME_A) $(ARGS_B)
xc:			all
	./$(NAME_B) $(ARGS_C) | ./$(NAME_A) $(ARGS_C)
xd:			all
	./$(NAME_B) $(ARGS_D) | ./$(NAME_A) $(ARGS_D)
xe:			all
	./$(NAME_B) $(ARGS_E) | ./$(NAME_A) $(ARGS_E)
