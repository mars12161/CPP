# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 16:03:27 by mschaub           #+#    #+#              #
#    Updated: 2023/03/17 16:08:53 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources and Objects

SRC = 	main.cpp \
		Zombie.cpp \
		randomChump.cpp \
		newZombie.cpp \

OBJS = $(SRC:.cpp=.o)

# Compiling

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = zombie

HEADER = Zombie.hpp

# Removing

RM = rm -f

# Colors

GREEN =	\e[92;5;118m
RED = \e[91;5;118m

#Rules

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
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
