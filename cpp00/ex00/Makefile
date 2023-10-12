# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:23:54 by mschaub           #+#    #+#              #
#    Updated: 2023/03/13 16:34:30 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources and Objects

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

# Compilation

cc = 	c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	megaphone

# Removing

RM = 	rm -f

# Colors

GREEN =	\e[92;5;118m

# Rules

%.o: %.cpp
	@$(cc) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	@$(cc) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)Compiling done\n"

clean:
	@$(RM) $(OBJS)
	@echo "Remove .o files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Remove executable"

re: fclean all

.PHONY: all clean fclean re

