# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:37:45 by kanykei           #+#    #+#              #
#    Updated: 2024/09/20 00:00:52 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	srcs

CC		=	c++
CFLAGS	=	-std=c++98 -pedantic -Wall -Wextra -Werror -MD 

NAME	=	ex00
SRC		=	main.cpp Hammer.cpp Shovel.cpp ATool.cpp Worker.cpp
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
INC		=	-I include

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "ex00 is compiled"

obj/%.o : %.cpp | obj
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re

# Run tests ===========================
check: ./$(NAME)
	./$(NAME)
# Run tests ===========================