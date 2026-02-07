SRCS = Data.cpp Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
D = $(OBJS:.o=.d)
CC = c++
FLAGS = - Wall -Wextra -Werror -MMD -std=c++98
NAME = Serializer

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(D)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(D)