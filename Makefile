# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/05 15:07:08 by mpetruno          #+#    #+#              #
#    Updated: 2018/10/10 15:00:03 by mpetruno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

SRC_DIR = ./src/

OBJ_DIR = ./obj/

INC_DIR = ./includes/

LIBFT_DIR = ./libft/

LIB = ./libft/libft.a

HEADER = $(INC_DIR)ft_printf.h

FILES = ft_printf.c \
		parsing.c \
		print_arg.c \
		arg_to_str_n.c \
		print_nums.c

SRC_FILES = $(addprefix $(SRC_DIR), $(FILES))

OFILES = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(HEADER) $(OFILES)
	@ar rc $(NAME) $(OFILES) $(LIBFT_DIR)*.o
	@ranlib $(NAME)
	@echo "libftprintf.a - DONE."

$(LIB):
	@echo "Compiling libft..."
	@make -C $(LIBFT_DIR) all --silent
	@echo "Libft compiling done."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY = all clean fclean re
