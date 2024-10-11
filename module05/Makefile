# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanykei <kanykei@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 13:37:45 by kanykei           #+#    #+#              #
#    Updated: 2024/10/11 23:44:57 by kanykei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	=	srcs
CC		=	c++
CFLAGS	=	-std=c++98 -MMD -fsanitize=address  #-Wall -Wextra -Werror

NAME	=	railnetwork
SRC		=	main.cpp Parser.cpp City.cpp Event.cpp Rail.cpp \
			Scheduler.cpp Train.cpp TrainComposition.cpp \
			PathFinder.cpp Speed.cpp TrainDispatcher.cpp
OBJ		=	$(addprefix obj/,$(notdir $(SRC:.cpp=.o)))
DEP		=	$(OBJ:.o=.d)
INC		=	-I include/infrastructure -I include/management -I include/logger

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ 
	@echo "railnetwork is compiled"

obj/%.o : %.cpp | obj
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj :
	@mkdir obj

clean :
	@rm -rf obj
	@rm *.log

fclean : clean
	@rm -f $(NAME)

re : clean all

-include $(DEP)

.PHONY : all clean fclean re

# Run tests ===========================
check: ./$(NAME)
	./$(NAME)
# Run tests ===========================