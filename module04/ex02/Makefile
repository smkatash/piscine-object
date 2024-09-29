# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:37:45 by kanykei           #+#    #+#              #
#    Updated: 2024/09/29 19:59:30 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	srcs
CC		=	c++
CFLAGS	=	-std=c++98 -pedantic -MMD  #-Wall -Wextra -Werror

NAME	=	ex02
SRC		=	main.cpp Course.cpp Form.cpp Person.cpp Room.cpp Staff.cpp Student.cpp
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
DEP		=	$(OBJ:.o=.d)
INC		=	-I include

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "ex02 is compiled"

obj/%.o : %.cpp | obj
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : clean all

-include $(DEP)

.PHONY : all clean fclean re

# Run tests ===========================
check: ./$(NAME)
	./$(NAME)
# Run tests ===========================