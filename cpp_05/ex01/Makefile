NAME = FormUp

CPP = c++
FLAGS = -Wall -Werror -Wextra
STD = -std=c++98
RM = rm -f
SRC = Bureaucrat.cpp main.cpp Form.cpp
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
