# Source

SRC =	main.cpp \
		Span.cpp \

OBJS =	$(SRC:.cpp=.o)

# Compiling

CC = 	c++

FLAGS =	-Wall -Wextra -Werror -std=c++98

NAME =	span

# Removing

RM =	rm -f

# Colors

GREEN =	\e[92;5;118m
RED = \e[91;5;118m

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Compiling done\n"

clean:
	@$(RM) $(OBJS)
	@printf "$(RED)Remove .o files\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Remove executable\n"

re: fclean all

.PHONY: all clean fclean re