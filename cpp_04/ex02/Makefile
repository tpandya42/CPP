NAME = JUSTanAbsolutE_ANIMAL

CPP = c++
FLAGS = -Wall -Werror -Wextra -I
STD = -std=c++98
RM = rm -f
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
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

