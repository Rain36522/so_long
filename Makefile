# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 08:09:16 by pudry             #+#    #+#              #
#    Updated: 2024/09/11 13:50:54 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a

MLX = mlx/libmlx.a
INCLUDES = -I ft_printf/includes -I get_next_line/includes -I ft_printf/libft/includes -I includes/
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit


BLUE = \\033[1;34m
WHITE = \\033[0;37m
YELLOW = \\033[0;33m
RED = \\033[1;31m
GREEN = \\033[1;32m
BRWN = \\033[0; 33m
GREY = \\033[1;30m

#utils/ft_check_map.c utils/ft_stock_map.c
SRC = $(wildcard src/*.c)
GNL_SRC += $(wildcard get_next_line/src/*.c)
OBJ = $(SRC:src/%.c=objet/%.o)
OBJ += $(GNL_SRC:get_next_line/src/%.c=objet/%.o)



all : lib $(NAME) header

	
$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_FLAGS) $(PRINTF) -o $(NAME)

lib :
	@make -C ft_printf/
	@make -C mlx/

clean :
	@rm -rf objet/
	@make clean -C ft_printf/
# @make clean -C mlx/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ft_printf/

re : fclean all

objet/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

objet/%.o: get_next_line/src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@ $(INCLUDES)

header :
	@echo "	      .-~~~-.        ${GREY}||${BLUE}::::::${RED}==========${WHITE}"
	@echo "	     /= ___  \       ${GREY}||${BLUE}::::::${WHITE}=========="
	@echo "	    |- /~~~\  |      ${GREY}||${BLUE}::::::${RED}==========${WHITE}"
	@echo "	    |=( ^.^ ) |      ${GREY}||${WHITE}================"
	@echo "	    \__\_=_/__/      ${GREY}||${RED}================${WHITE}"
	@echo "	     {_______}       ${GREY}||${WHITE}================"
	@echo "	   /  *       ~ --._ ${GREY}||${WHITE}"
	@echo "	  /= .     [] .     |  >"
	@echo "	 /  /|ooo     |  --^ ${GREY}||${WHITE}"
	@echo "	(   )\_______/       ${GREY}||${WHITE}"
	@echo "	 \..\//       \      ${GREY}||${WHITE}"
	@echo "	  ^-| ==    \_|      ${GREY}||${WHITE}"
	@echo "	    /         |      ${GREY}||${WHITE}"
	@echo "	   |=   >\  __/      ${GREY}||${WHITE}"
	@echo "	   \   \ |- --|      ${GREY}||${WHITE}"
	@echo "	    \ __| \___/      ${GREY}||${WHITE}"
	@echo "	     [__] _[__]      ${GREY}||${WHITE}"
	@echo "	   (    )(    )      ${GREY}||${WHITE}"
	@echo "	^^~ ^^^^^  ^^^^  ~^^^~^^~~~^^^~^^^~^^^~^^~^"



.PHONY : fclean re all header clean lib