NAME = wolf3d

FLAG = -Wall -Werror -Wextra

SRC = wolf3d.c

OBJ= wolf3d.o

LIBX = -lm -L libft/ -lft -I/usr/local/include -I/usr/local/lib \
	   	   -Lminilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	make -C ./minilibx
	make -C ./libft
	gcc $(FLAG) -c $(SRC)
	gcc $(LIBX) $(OBJ) -o $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
