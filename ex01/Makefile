# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asauvage <asauvage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 11:52:07 by asauvage          #+#    #+#              #
#    Updated: 2026/09/14 18:18:51 by asauvage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = Serializer

SRCS = main.cpp \
	   Serializer.cpp

OBJS := $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re