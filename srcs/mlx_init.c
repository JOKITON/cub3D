/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 12:24:47 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	in_grid(t_grid	*grid)
{
	grid->screenHeight = 1920;
	grid->screenWidth = 1080;

	// Grid input needed
	grid->mapHeight = 0;
	grid->mapWidth = 0;

	grid->posX = 0;
	grid->posY = 0;

	grid->dirX = (double)-1;
	grid->dirY = (double)0;

	grid->cameraX = (double)0;
	grid->cameraY = (double)0.66;

	grid->rayDirX = (double)0;
	grid->rayDirY = (double)0;
}

void	in_mlx(t_mlx	*mlx)
{
	mlx_init(&mlx->init);
	mlx_new_window(&mlx->init, 1920, 1080, "cub3D");
	mlx->img_win = mlx_new_image(&mlx->init, 1920, 1080);
	mlx->img_addr = mlx_get_data_addr(&mlx->init,
			mlx->bits_per_pixel, mlx->line_length, mlx->endian);
}

