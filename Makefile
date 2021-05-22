# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtak <mtak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 14:37:13 by mtak              #+#    #+#              #
#    Updated: 2021/05/22 20:51:58 by mtak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAG	= -g#-Wall -Wextra -Werror 
HEADER	= -I./include

SRC_NAME = main.c\
			action_p.c\
			action_r.c\
			action_rr.c\
			action_s.c\
			init.c\
			util.c

SRC_PATH = ./src

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAG) $(HEADER) -o $@ -c $<

LIBFT	= libft.a

LIB = -L./libft -lft

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	gcc -o $(NAME) $(OBJ)  $(HEADER) $(CFLAG) $(LIB)

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJ_PATH)

fclean:
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re