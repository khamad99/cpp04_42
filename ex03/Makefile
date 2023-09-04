
NAME	= main

CXX		= c++

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp LeftOver.cpp

OBJ = $(SRC:%.cpp=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
