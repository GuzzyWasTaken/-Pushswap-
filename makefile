# Name
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
debug = -Wall -Wextra -Werror -Wall -Wextra -Werror -g
CC = gcc

# Source Files
HDR_SRC		=	push_swap.h
HDR_DIR		=	includes/
HEADER		=	$(addprefix $(HDR_DIR), $(HDR_SRC))
MANDA_SRC	:=	push_swap.c push_utils.c push_moves.c hardcode.c main.c more_push_moves.c parsing.c ft_split.c parse_strings.c
MANDA_DIR	:=	src/
SRC			:=	$(addprefix $(MANDA_DIR), $(MANDA_SRC))

$(NAME): $(SRC) $(HEADER)
	${CC} ${FLAGS} $(SRC) -o $(NAME)

debug: $(SRC) $(HEADER)
	${CC} $(DEBUG) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re