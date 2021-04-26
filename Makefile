# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 13:47:34 by rvoltigo          #+#    #+#              #
#    Updated: 2020/12/06 13:47:36 by rvoltigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEAD = include/ft_printf_func.h \
		ft_printf.h

SRC =	src/create_struct.c \
		src/display_u.c \
		src/parse_other_types.c \
		src/display_c.c \
		src/display_x.c \
		src/parser.c \
		src/display_d.c \
		src/flags.c \
		src/print_null.c \
		src/display_hex.c \
		src/ft_puts.c \
		src/print_space.c \
		src/display_p.c \
		src/mem_width.c \
		src/parse_stars.c \
		src/display_percent.c \
		src/other_functions.c \
		src/unum_longnum.c \
		src/display_s.c \
		src/parse_flag_s.c \
		ft_printf.c

%.o: %.c $(HEAD)
	gcc $(FLAGS) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	$(MAKE) all -C ./libft
	$(MAKE) bonus -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	
re: fclean all

bonus:
	$(MAKE) all

.PHONY: all clean fclean re bonus
