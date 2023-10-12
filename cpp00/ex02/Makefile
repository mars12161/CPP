# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 20:41:20 by mschaub           #+#    #+#              #
#    Updated: 2023/03/08 20:43:43 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources and Objects

SRC = Account.cpp \
	  tests.cpp \

OBJS = $(SRC:.cpp=.o)

# Compilation

cc = 	c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	account

HEADER = Account.hpp

# Removing

RM = 	rm -f

# Colors

GREEN =	\e[92;5;118m

# Rules

%.o: %.cpp $(HEADER)
	@$(cc) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(cc) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Compiling done\n"

clean:
	@$(RM) $(OBJS)
	@printf "Remove .o files\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "Remove executable\n"

re: fclean all

.PHONY: all clean fclean re