# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbartos <vbartos@student.42prague.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:14:33 by vbartos           #+#    #+#              #
#    Updated: 2023/10/07 11:49:11 by vbartos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOURS ---------------------------------- #

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

# PROJECT ---------------------------------- #

NAME			= libft.a

# FLAGS ------------------------------------ #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

# SOURCE FILES ----------------------------- #

SRCS			= ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_calloc.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_itoa.c\
				ft_split.c\
				ft_strtrim.c\
				ft_strmapi.c\
				ft_striteri.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c\
				\
				ft_printf.c\
				ft_sort.c\
				ft_putchar.c\
				ft_putnbr.c\
				ft_putstr.c\
				ft_putunsigned.c\
				ft_hexadec.c\
				ft_putptr.c\
				\
				get_next_line.c\

# OBJECT FILES ----------------------------- #

OBJS = ${SRCS:.c=.o}

# RULES ------------------------------------ #

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}
	@echo "$(RED) - Libft object files removed.$(RESET)"

fclean: clean
	${RM} $(NAME)
	@echo "$(RED) - Libft binary files removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re