# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 20:49:06 by anestor           #+#    #+#              #
#    Updated: 2018/01/15 22:30:14 by anestor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror

SRC = 
SRC += main.c
SRC += read.c
SRC += vector.c
SRC += hooks.c
SRC += render.c
SRC += grid.c
SRC += bonuscolors.c

OBJ        = $(patsubst %.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(FLAGS) -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit obj/*.o -o $(NAME)

obj/%.o: %.c
	@mkdir -p obj
	@gcc $(FLAGS) -c $< -o $@
	@echo "... compiling $< ..."

clean:
	@/bin/rm -rf obj/
	@make -C libft/ clean
	@echo "... cleaning fdf obj ..."

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@echo "... cleaning $(NAME) ..."

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all test
