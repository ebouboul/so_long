# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 13:08:38 by ebouboul          #+#    #+#              #
#    Updated: 2024/05/21 13:40:27 by ebouboul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
# LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 
LIBFT = ./libft/libft.a
RM = rm -rf
MLXFLAGS =  -Lminilibx-linux -lmlx -lX11 -lXext -lm

SRC = so_long.c \
      get_next_line.c \
      get_next_line_utils.c \
	  parsing.c\
	  flood_fill.c\
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) --no-print-directory -C ./libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME) #$(LIBS)

%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	$(MAKE) clean --no-print-directory -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean --no-print-directory -C ./libft
	$(RM) $(NAME)

re: fclean all
