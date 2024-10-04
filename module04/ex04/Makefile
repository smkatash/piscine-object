# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:37:45 by kanykei           #+#    #+#              #
#    Updated: 2024/10/03 19:38:14 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	srcs
CC		=	c++
CFLAGS	=	-std=c++98 -pedantic -MMD  #-Wall -Wextra -Werror

NAME	=	ex04
SRC		=	main.cpp Course.cpp Form.cpp Person.cpp Room.cpp Staff.cpp Student.cpp Headmaster.cpp Professor.cpp Secretary.cpp Observer.cpp
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
DEP		=	$(OBJ:.o=.d)
INC		=	-I include

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "ex04 is compiled"

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