# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/05/16 11:11:16 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

MLIB = libmlx.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

# Libraries
LIB_DIR = minilibx-linux/
MINILIB_LIB = $(addprefix $(LIB_DIR), libmlx_Linux.a)

LIBFT_DIR = libft/
LIBFT_LIB = $(addprefix $(LIBFT_DIR), libft.a)

#SRCS
SOURCE_TREE = main

IMAGE_SRC = mlx_init image vectors color_vectors

MAP_SRC = map param umap utils valid

LIB_SRC = ft_memset ft_calloc ft_split ft_strcmp ft_strdup \
			ft_strjoin ft_strlen ft_strncpy ft_strvld

GNL_SRC = get_next_line

SRC = 	$(addsuffix .c, $(SOURCE_TREE)) \
		$(addsuffix .c, $(addprefix images/, $(IMAGE_SRC))) \
		$(addsuffix .c, $(addprefix $(LIBFT_DIR), $(LIB_SRC))) \
		$(addsuffix .c, $(addprefix get_next_line/, $(GNL_SRC))) \
		$(addsuffix .c, $(addprefix map/, $(MAP_SRC)))

SRCDIR = srcs/
SRCS := $(addprefix $(SRCDIR), $(SRC))

#OBJS
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#FLAGS & UTILS
RM = rm

RM_FLAGS = -rf

UTILS = -g3 -v -fsanitize=address

#INCLUDES
INCLUDES = -I includes/
LIBX_IN = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(OBJ_DIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(UTILS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $^ $(LIBFT_LIB) $(MINILIB_LIB) $(LIBX_IN) -o $(NAME)
clean:
	make -C $(LIB_DIR) clean
	make -C $(LIBFT_DIR) clean
	$(RM) $(RM_FLAGS) objs/

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re