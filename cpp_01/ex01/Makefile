NAME = Moar_Brainz!

CPP = c++
FLAGS = -Wall -Werror -Wextra -I
STD = -std=c++98
RM = rm -f
SRC = Zombie.cpp zombieHorde.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(STD) $(OBJ) -o $(NAME)

.cpp.o:
	$(CPP) $(FLAGS) $(STD) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

