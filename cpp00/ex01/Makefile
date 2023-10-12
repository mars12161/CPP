# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 09:29:27 by mschaub           #+#    #+#              #
#    Updated: 2023/04/10 16:07:28 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources and Objects

SRC = Contact.cpp \
	  PhoneBook.cpp \
	  main.cpp \

OBJS = 	$(SRC:.cpp=.o)

# Compiling

cc =		c++

FLAGS =		-Wall -Wextra -Werror -std=c++98

NAME =		phonebook

HEADER =	Contact.hpp \
			PhoneBook.hpp \

# Removing

RM =	rm -f

# Colors

GREEN =	\e[92;5;118m


# Rules

%.o: %.cpp
	@$(cc) $(FLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(cc) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Compiling done\n"

clean:
	@$(RM) $(OBJS)
	@echo "Remove .o files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Remove executable"

re: fclean all

.PHONY: all clean fclean re