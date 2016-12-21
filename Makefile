NAME = wolf3d

FLAG = -Wall -Werror -Wextra

SRC =  color.c display.c env.c key.c \
main.c map.c move.c move_ext.c wolf3d.c

OBJ = color.o display.o env.o key.o \
main.o map.o move.o move_ext.o wolf3d.o

LIBX = -lm -L libft/ -lft -I/usr/local/include -I/usr/local/lib \
	-Lminilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	make -C ./minilibx
	make -C ./Libft
	gcc $(FLAG) -c $(SRC)
	gcc $(LIBX) $(OBJ) -o $(NAME)

clean:
	make -C ./Libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ./Libft fclean
	rm -f $(NAME)

re: fclean all
