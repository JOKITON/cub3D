# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/05/01 16:39:39 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

MLIB = libmlx.a

LIB_DIR = minilibx-linux/

LIBFT_DIR = libft/

LIBFT_LIB = libft.a

C_DIR = .

RM = rm

MV = mv

RM_FLAGS = -rf

UTILS2 = -g3 -v

CC = cc

UTILS = main.c init_mlx.c
	
OBJS = $(UTILS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS): $(UTILS)
	$(CC) $(FLAGS) -c $^

$(NAME): $(OBJS)
	make -C $(LIB_DIR) all
	make -C $(LIBFT_DIR) all
	$(MV) $(LIB_DIR)$(MLIB) $(C_DIR)
	$(MV) $(LIBFT_DIR)$(LIBFT_LIB) $(C_DIR)
	$(CC) $(FLAGS) $(LIBFT_LIB) $(MLIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -lm $(OBJS) -o $(NAME)

clean:
	make -C $(LIB_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(RM_FLAGS) $(MLIB)
	$(RM) $(RM_FLAGS) $(LIBFT_LIB)
	$(RM) $(RM_FLAGS) $(OBJS)

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re