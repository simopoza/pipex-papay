NAME= pipex
CC= gcc
FLAGS= -Wall -Wextra -Werror
SRC= main.c pipex.c check_cmd.c check_files.c pipex_utils.c split_path.c
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all