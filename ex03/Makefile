# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 11:08:12 by ryabuki           #+#    #+#              #
#    Updated: 2025/05/13 16:55:28 by ryabuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -g
INCLUDES = -I includes

SRCS =	srcs/main.cpp \
		srcs/Bureaucrat.cpp \
		srcs/AForm.cpp \
		srcs/ShrubberyCreationForm.cpp \
		srcs/RobotomyRequestForm.cpp \
		srcs/PresidentialPardonForm.cpp \
		srcs/Intern.cpp \


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) garden_shrubbery

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re