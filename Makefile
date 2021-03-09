# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-capu <fde-capu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 16:20:12 by fde-capu          #+#    #+#              #
#    Updated: 2021/03/09 15:57:17 by fde-capu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARGS_A		=	1 2 3
NAME_A		=	checker
NAME_B		=	push_swap
SRCS_A		=	checker.c
SRCS_B		=	push_swap.c
HEADS_A		=	checker.h
HEADS_B		=	push_swap.h
SRCS_COMMON	=	args.c ft_atoi.c ft_isdigit.c ft_strtrim.c \
	ft_calloc.c ft_bzero.c ft_chrinset.c ft_regex.c \
	ft_regex_h1.c ft_regex_h2.c ft_insplit.c ft_strnstr.c \
	ft_inskip.c ft_findstr.c ft_strlcpy.c ft_strlen.c \
	ft_strfree2d.c ft_substr.c args_helpers.c stack.c \
	ft_itoa.c ft_strcat.c ft_print.c ft_split.c ft_strdup.c \
	ft_xlloc.c ft_strcpy.c stack_init.c stack_ops.c
HEAD_COMMON	=	common.h
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

rea:	fcleana $(NAME_A)
reb:	fcleanb $(NAME_B)
re:		fclean all

ta:		$(NAME_A)
	-./$(NAME_A) $(ARGS_A)
tb:		$(NAME_B)
	-./$(NAME_B) $(ARGS_B)
t:		ta tb

rta:	rea ta
rtb:	reb tb
rt:		re t
tt:		rt

vv:	re v
rv:	vv
va:	$(NAME_A)
	-$(VALGRIND) ./$(NAME_A) $(ARGS_A)
vb:	$(NAME_B)
	-$(VALGRIND) ./$(NAME_B) $(ARGS_B)
v:	va vb

vfa: $(NAME_A)
	-$(VALGRIND) $(VALGFLAGS) ./$(NAME_A) $(ARGS_A)
vfb: $(NAME_B)
	-$(VALGRIND) $(VALGFLAGS) ./$(NAME_B) $(ARGS_B)
vf:	vfa vfb
