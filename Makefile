# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/05/31 12:24:58 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D


CC = gcc

#FLAGS = -Wall -Wextra -Werror

# Libraries
MLIB = libmlx.a

MINILIB_MAC_DIR = MLX42/
MINILIB_MAC = $(addprefix $(MINILIB_MAC_DIR), $(MLIB))

LIBFT_DIR = libft/
LIBFT_LIB = $(addprefix $(LIBFT_DIR), libft.a)

#SRCS
SOURCE_TREE = main

IMAGE_SRC = mlx_init map_image map_vectors map_colors map_time

MAP_SRC = map param umap utils valid trim_dir

LIB_SRC = ft_memset ft_calloc ft_split ft_strcmp ft_strdup \
			ft_strjoin ft_strlen ft_strncpy ft_strvld

HOOK_SRC = get_hooks moves_map moves_cam

GNL_SRC = get_next_line

SRC = 	$(addsuffix .c, $(SOURCE_TREE)) \
		$(addsuffix .c, $(addprefix images/, $(IMAGE_SRC))) \
		$(addsuffix .c, $(addprefix $(LIBFT_DIR), $(LIB_SRC))) \
		$(addsuffix .c, $(addprefix get_next_line/, $(GNL_SRC))) \
		$(addsuffix .c, $(addprefix map/, $(MAP_SRC))) \
		$(addsuffix .c, $(addprefix hooks/, $(HOOK_SRC)))

SRCDIR = srcs/
SRCS := $(addprefix $(SRCDIR), $(SRC))

#OBJS
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#FLAGS & UTILS
RM = rm

RM_FLAGS = -rf

FSANITIZE = -g3 -v

#INCLUDES
LIBMLX	:= ./lib/MLX42
INCLUDES := -I ./include -I MLX42/include
LIBS	:= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
FLAGS_LIBX = -L . -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ_DIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(FLAGS) $(FSANITIZE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

clean:
	$(RM) $(RM_FLAGS) objs/

fclean: clean
	$(RM) $(RM_FLAGS) $(NAME)

re: fclean all

.PHONY : all clean fclean re