# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 19:27:10 by lshellie          #+#    #+#              #
#    Updated: 2019/06/02 13:17:36 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILE = ft_isalpha.c ft_lstadd.c ft_lstnew.c ft_memcpy.c ft_putchar_fd.c \
		ft_putstr.c ft_strcmp.c ft_striter.c ft_strmap.c ft_strnequ.c \
		ft_strstr.c ft_isascii.c ft_lstdel.c ft_memalloc.c ft_memdel.c \
		ft_putendl.c ft_putstr_fd.c ft_strcpy.c ft_striteri.c ft_strmapi.c \
		ft_strnew.c ft_strsub.c ft_atoi.c ft_isdigit.c ft_lstdelone.c \
		ft_memccpy.c ft_memmove.c ft_putendl_fd.c ft_strcat.c ft_strdel.c \
		ft_strjoin.c ft_strncat.c ft_strnstr.c ft_strtrim.c ft_bzero.c \
		ft_isprint.c ft_lstiter.c ft_memchr.c ft_memset.c ft_putnbr.c \
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strrchr.c \
		ft_tolower.c ft_isalnum.c ft_itoa.c ft_lstmap.c ft_memcmp.c \
		ft_putchar.c ft_putnbr_fd.c ft_strclr.c ft_strequ.c \
		ft_strlen.c ft_strncpy.c ft_strsplit.c ft_toupper.c ft_sqrt.c \
		ft_strstr_kmp.c ft_zfunc.c ft_is_prime.c ft_gcd.c ft_fast_bin_pow.c ft_fast_bit_pow.c \
		get_next_line.c ft_rev_str.c ft_abs.c

OFILE = ft_isalpha.o ft_lstadd.o ft_lstnew.o ft_memcpy.o ft_putchar_fd.o \
        ft_putstr.o ft_strcmp.o ft_striter.o ft_strmap.o ft_strnequ.o \
        ft_strstr.o ft_isascii.o ft_lstdel.o ft_memalloc.o ft_memdel.o \
        ft_putendl.o ft_putstr_fd.o ft_strcpy.o ft_striteri.o ft_strmapi.o \
        ft_strnew.o ft_strsub.o ft_atoi.o ft_isdigit.o ft_lstdelone.o \
        ft_memccpy.o ft_memmove.o ft_putendl_fd.o ft_strcat.o ft_strdel.o \
        ft_strjoin.o ft_strncat.o ft_strnstr.o ft_strtrim.o ft_bzero.o \
        ft_isprint.o ft_lstiter.o ft_memchr.o ft_memset.o ft_putnbr.o \
        ft_strchr.o ft_strdup.o ft_strlcat.o ft_strncmp.o ft_strrchr.o \
       	ft_tolower.o ft_isalnum.o ft_itoa.o ft_lstmap.o ft_memcmp.o \
        ft_putchar.o ft_putnbr_fd.o ft_strclr.o ft_strequ.o \
        ft_strlen.o ft_strncpy.o ft_strsplit.o ft_toupper.o ft_sqrt.o \
        ft_strstr_kmp.o ft_zfunc.o ft_is_prime.o ft_gcd.o ft_fast_bin_pow.o ft_fast_bit_pow.o \
        get_next_line.o ft_rev_str.o ft_abs.o

HFILE = libft.h

all: $(NAME)

$(NAME): $(OFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

%.o: %.c $(HFILE)
	gcc -Wall -Werror -Wextra -I $(HFILE) -c $< -o $@

clean: 
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
