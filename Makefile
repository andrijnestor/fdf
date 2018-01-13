
NAME = fdf
#no flags
SRC = 
SRC += main.c
SRC += read.c
SRC += vector.c
SRC += hooks.c

OBJ        = $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc  -L libft/ -lft -g -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME) -g
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create FdF"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
.PHONY: clean fclean re all test
