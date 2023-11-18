# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:14:33 by vbartos           #+#    #+#              #
#    Updated: 2023/10/26 17:28:50 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# PROJECT ---------------------------------- #

NAME			= so_long

# FLAGS ------------------------------------ #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -rf
MLX_FLAGS		= -Lminilibx_linux -lmlx -L/usr/lib/X11 -lXext -lX11

# LIBRARIES -------------------------------- #

LIBFT_PATH 		= libft/
LIBFT_NAME		= libft.a
LIBFT 			= $(LIBFT_PATH)$(LIBFT_NAME)
MLX_PATH		= minilibx_linux/
MLX_NAME		= libmlx.a
MLX 			= $(MLX_PATH)$(MLX_NAME)

# SOURCE FILES ----------------------------- #

SRC_PATH		= src/
SRC				= so_long.c\
					map_checker.c\
					map_parser.c\
					mlx_init.c\
					gameplay.c\
					free.c\
					utils.c
SRCS			= $(addprefix $(SRC_PATH), $(SRC))

#SRCS_BONUS		= 

# OBJECT FILES ----------------------------- #

OBJ_PATH		= obj/
OBJ				= $(SRC:.c=.o)
OBJS			= $(addprefix $(OBJ_PATH), $(OBJ))

#OBJS_BONUS		=

# INCLUDES --------------------------------- #

INC 			= -I ./inc/\
				  -I ./libft/\
				  -I ./minilibx_linux/\
				  -I/usr/include

# RULES ------------------------------------ #

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@echo "$(GREEN) - Libft compiled.$(RESET)"

$(MLX):
	@make -sC $(MLX_PATH)
	@echo "$(GREEN) - MiniLibX compiled.$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(INC) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN) - Project compiled.$(RESET)"

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	@${RM} $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@echo "$(RED) - Project object files deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC $(LIBFT_PATH)
	@echo "$(RED) - Project object & binary files deleted.$(RESET)"

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus