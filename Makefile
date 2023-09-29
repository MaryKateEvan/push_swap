# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mevangel <mevangel@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 23:25:04 by mevangel          #+#    #+#              #
#    Updated: 2023/09/29 22:46:34 by mevangel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

################################################################
#####                FOR THE MADATORY PART:                #####
################################################################

NAME		=	push_swap

OBJ_DIR		=	./obj/

SRC		=	main.c \
			parsing.c \
			stack_utils.c \
			operations.c \
			sorting.c \
			utils.c \

OBJ		=	$(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

################################################################
#####                    FOR BONUS PART:                   #####
################################################################

B_NAME		=	checker

B_SRC_DIR	=	./bonus/
B_OBJ_DIR	=	./bonus/obj/

B_SRC		=	$(B_SRC_DIR)checker.c \
				$(B_SRC_DIR)parsing.c \
				$(B_SRC_DIR)stack_utils.c \
				$(B_SRC_DIR)operations.c \
				$(B_SRC_DIR)utils.c \
				$(B_SRC_DIR)get_next_line.c \
				$(B_SRC_DIR)get_next_line_utils.c

B_OBJ		=	$(B_SRC:$(B_SRC_DIR)%.c=$(B_OBJ_DIR)%.o)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(B_NAME)

$(B_OBJ_DIR)%.o: $(B_SRC_DIR)%.c
	mkdir -p $(B_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

################################################################
#####                        GENERAL:                      #####
################################################################

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(B_OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
