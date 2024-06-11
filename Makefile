# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 13:08:38 by ebouboul          #+#    #+#              #
#    Updated: 2024/06/11 22:36:25 by ebouboul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
# LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
RM = rm -rf
MLXFLAGS =  -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRC = so_long.c \
      get_next_line.c \
      get_next_line_utils.c \
	  parsing.c\
	  flood_fill.c\
	  window_func.c\
	  key_hand.c\
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  $(MLXFLAGS) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
