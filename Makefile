# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/05/09 14:32:08 by jaizpuru         ###   ########.fr        #
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

UTILS_NAME = main.c mlx_init.c image.c

UTILS = $(addprefix srcs/, $(UTILS_NAME))

OBJ = $(UTILS_NAME:.c=.o)

OBJS = $(addprefix objs/, $(UTILS_NAME:.c=.o))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

objs/ :
	mkdir objs/

$(OBJS): $(UTILS) objs/
	$(CC) $(FLAGS) -c $^
	mv $(OBJ) objs/

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
	$(RM) $(RM_FLAGS) objs/

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re