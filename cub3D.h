/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:37 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/01 16:37:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct s_grid
{
	int	mapWeight; // 2d grid
	int	mapHeight;

	int	screenWeight; // minilibX-image
	int	screenHeight;

	int	posX; // starting pos of character & Pos Vector
	int	posY;

	int	dirX; // initial pos of Direction Vector
	int	dirY;

	int	planeX; // Camera Vector
	int	planeY;
} t_grid;

typedef	struct s_mlx
{
	void	*init;
	char	*img;
} t_mlx;

void	init_mlx(t_mlx	*mlx);

#endif