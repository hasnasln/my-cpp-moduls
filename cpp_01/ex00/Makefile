NAME = zombi
FLAGS = c++ -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC =	main.cpp\
		newZombie.cpp\
		randomChump.cpp\
		Zombie.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)


$(NAME):$(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean 