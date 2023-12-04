# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:05:25 by emsoares          #+#    #+#              #
#    Updated: 2023/12/01 10:05:28 by emsoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET   = \033[0m
BLACK   = \033[1;30m
RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
PURPLE  = \033[1;35m
CYAN    = \033[1;36m
WHITE   = \033[1;37m

NAME = ex01

CXX = c++

CXXFLAGS = -g -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS = main.cpp \
			Serializer.cpp \

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	clear
	@echo "$(GREEN)./ex01 executable is ready!$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Object files have been deleted!$(RESET)"

fclean: clean
	@$(RM) $(NAME) 
	clear
	@echo "$(RED)Object and Executable files have been deleted!$(RESET)"

re: fclean all