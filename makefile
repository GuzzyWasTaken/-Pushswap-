# Name
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
CC = gcc

# Source Files
SOURCE = Push_swap.c\
		push_swap.h\
		push_utils.c\
		push_moves.c\
		hardcode.c\
		main.c\
		more_push_moves.c\

OBJECTS = $(SOURCE:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $<
	@echo "Compiling: $<"

$(NAME) : $(OBJECTS)
		@ar -rcs $(NAME) $(OBJECTS)
		@echo "Compiling!"

all: $(NAME)
