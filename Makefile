##
## EPITECH PROJECT, 2023
## SAMY
## File description:
## MY_HUNTER
##


SRC =   $(wildcard *.c)

OBJ =   $(patsubst %.c, %.o, $(SRC))

NAME =   my_hunter

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

U = -L/opt/homebrew/Cellar/csfml/2.5.2_1/lib
I = -I/opt/homebrew/Cellar/csfml/2.5.2_1/include

all:    $(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC)   $(CSFML) $(U) $(I)

clean:
		rm -f $ *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
