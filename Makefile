# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 10:53:48 by ismelich          #+#    #+#              #
#    Updated: 2019/12/09 11:23:34 by ismelich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBDIR = libft/
HEADERDIR = libft/

LIB = $(LIBDIR)libft.a

SRC = main.c grid.c matrix.c tetro_checker.c solver.c read_input.c error.c

OBJ = main.o grid.o matrix.o tetro_checker.o solver.o read_input.o error.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	$(CC) $(SRC) $(FLAGS) -o $(NAME) $(LIB) -I $(HEADERDIR)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all
