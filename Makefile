##
## EPITECH PROJECT, 2024
## Epitech
## File description:
## Makefile Minishell1
##

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

NAME = mysh

LDFLAGS =	-L./lib/my -lmy	-g3

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	@$(MAKE) -C lib/my clean
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C lib/my fclean
	$(RM) $(NAME) libmy.a

re: fclean all
