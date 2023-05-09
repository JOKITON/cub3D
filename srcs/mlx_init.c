/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/09 15:49:52 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	in_grid(t_grid	*grid)
{
	t_vector	*vec;
	t_colors	*colors;

	vec = malloc(sizeof(vec));
	colors = malloc(sizeof(colors));
	ft_memset(&vec, 0, sizeof(vec));
	ft_memset(&colors, 0, sizeof(colors));
	grid->vec = vec;
	grid->screenHeight = 1920;
	grid->screenWidth = 1080;
	grid->dirX = (double)-1;
	grid->cameraY = (double)0.66;
	// Vector struct
}

void	in_mlx(t_mlx	*mlx)
{
	mlx_init(&mlx->init);
	mlx_new_window(&mlx->init, 1920, 1080, "cub3D");
	mlx->img_win = mlx_new_image(&mlx->init, 1920, 1080);
	mlx->img_addr = mlx_get_data_addr(&mlx->init,
			mlx->bits_per_pixel, mlx->line_length, mlx->endian);
	
	t_grid	*grid;

	grid = malloc(sizeof(grid));
	ft_memset(&grid, 0, sizeof(grid));
	mlx->grid = grid;
}

