# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:42:01 by jaizpuru          #+#    #+#              #
#    Updated: 2023/05/11 21:30:54 by jaizpuru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

MLIB = libmlx.a

# Libraries
LIB_DIR = minilibx-linux/
MINILIB_LIB = $(addprefix $LIB_DIR, libmlx_Linux.a)

LIBFT_DIR = libft/
LIBFT_LIB = $(addprefix $LIBFT_DIR, libft.a)

C_DIR = .

RM = rm

MV = mv

RM_FLAGS = -rf

UTILS2 = -g3 -v

CC = gcc

SRCDIR = srcs/
SRC = main.c mlx_init.c image.c \
		vectors.c color_vectors.c \
		ft_memset.c
SRCS := $(addprefix $(SRCDIR), $(SRC))

OBJDIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_DIR = objs/

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes/cub3D.h
LIBX_IN = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $^ $(LIBFT_LIB) $(MINILIB_LIB) $(LIBX_IN) -o $(NAME)
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