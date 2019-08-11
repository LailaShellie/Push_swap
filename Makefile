# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 19:00:35 by lshellie          #+#    #+#              #
#    Updated: 2019/07/21 19:30:24 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_SRC = $(addprefix checker_sources/, checker.c commands.c)

PUSH_SWAP_SRC = $(addprefix push_swap_sources/, push_swap_main.c \
			solve_three.c solve_hundred.c calculate.c borders.c execute.c)

STACK_SRC = $(addprefix stack_sources/, a_commands.c b_commands.c both_commands.c stack.c \
			validation.c  check_overflow.c error.c input.c)

CHECKER_OBJ = checker.o commands.o

PUSH_SWAP_OBJ = push_swap_main.o solve_three.o solve_hundred.o calculate.o borders.o execute.o

STACK_OBJ = a_commands.o b_commands.o both_commands.o stack.o validation.o check_overflow.o error.o input.o

STACK_HEADER = stack_sources/stack.h

CHECKER_HEADER = checker_sources/checker.h

PUSH_SWAP_HEADER = push_swap_sources/push_swap.h

CHECKER_NAME = checker

PUSH_SWAP_NAME = push_swap

LIB = libft/libft.a

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(LIB) $(CHECKER_OBJ) $(STACK_OBJ)
	gcc -Wall -Wextra -Werror -g -o $@ -L. $(LIB) $(CHECKER_OBJ) $(STACK_OBJ)
$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	gcc -Wall -Wextra -Werror -g -o $@ -L. $(LIB) $(PUSH_SWAP_OBJ) $(STACK_OBJ)
$(STACK_OBJ):
	gcc -I $(STACK_HEADER) -c $(STACK_SRC)
$(CHECKER_OBJ):
	gcc -I $(CHECKER_HEADER) -c $(CHECKER_SRC)
$(PUSH_SWAP_OBJ):
	gcc -I $(PUSH_SWAP_HEADER) -c $(PUSH_SWAP_SRC)
$(LIB):
	make -C ./libft
clean:
	make clean -C ./libft
	rm -rf $(STACK_OBJ) $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
fclean: clean
	make fclean -C ./libft
	rm -rf $(CHECKER_NAME) $(PUSH_SWAP_NAME)
re: fclean all