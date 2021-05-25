# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:32:59 by mtak              #+#    #+#              #
#    Updated: 2021/05/24 14:24:30 by mtak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAG	= -g -Wall -Wextra -Werror 

SRC_NAME =  main_ps.c get_median.c solver.c a_functions.c b_functions.c \
			build.c run_commands.c parse_nb_from_str.c\
			util.c util2.c util3.c

SRC_PATH = ./src

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAG) -o $@ -c $<

all: $(NAME)

$(NAME) : $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAG)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re