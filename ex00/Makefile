CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ScalarConverter

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all
