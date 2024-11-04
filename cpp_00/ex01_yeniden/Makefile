NAME = my_phonebook
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = phone_book.cpp contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	g++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re