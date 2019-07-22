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

CHECKER_SRC = $(addprefix checker_sources/, checker.c validation.c error.c commands.c)

STACK_SRC = $(addprefix stack_sources/, a_commands.c b_commands.c both_commands.c stack.c)

CHECKER_OBJ = checker.o validation.o error.o commands.o

STACK_OBJ = a_commands.o b_commands.o both_commands.o stack.o

STACK_HEADER = stack_sources/stack.h

CHECKER_HEADER = checker_sources/checker.h

CHECKER_NAME = checker

LIB = libft/libft.a

all: $(CHECKER_NAME)

$(CHECKER_NAME): $(LIB) $(CHECKER_OBJ) $(STACK_OBJ)
	gcc -Wall -Wextra -Werror -o $@ -L. $(LIB) $(CHECKER_OBJ) $(STACK_OBJ)
$(STACK_OBJ):
	gcc -I. $(STACK_HEADER) -c $(STACK_SRC)
$(CHECKER_OBJ):
	gcc -I. $(CHECKER_HEADER) -c $(CHECKER_SRC)
$(LIB):
	make -C ./libft
clean:
	make clean -C ./libft
	rm -rf $(STACK_OBJ) $(CHECKER_OBJ)
fclean: clean
	make fclean -C ./libft
	rm -rf $(CHECKER_NAME)
re: fclean all