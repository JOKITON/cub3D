/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 10:51:37 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	in_grid(t_grid	*grid, t_map *map)
{
	t_vector	*vec;
	t_colors	*colors;

	vec = malloc(sizeof(vec));
	ft_memset(&vec, 0, sizeof(vec));
	grid->vec = vec;
	colors = malloc(sizeof(colors));
	ft_memset(&colors, 0, sizeof(colors));
	grid->screen_height = 1920;
	grid->screen_width = 1080;
	grid->dir_x = (double)-1;
	grid->camera_y = (double)0.66;
	grid->pos_x = map->x;
	grid->pos_y = map->y;
}

void	in_mlx(t_mlx *mlx)
{
	mlx_init(mlx->init);
	mlx_new_window(mlx->init, 1920, 1080, "cub3D");
	mlx->img_win = mlx_new_image(mlx->init, 1920, 1080);
	mlx->img_addr = mlx_get_data_addr(mlx->init,
			mlx->bits_per_pixel, mlx->line_length, mlx->endian);
}

void	in_structs(t_mlx *mlx, t_map	*map)
{
	t_grid	*grid;

	mlx = malloc(sizeof(mlx));
	ft_memset(mlx, 0, sizeof(mlx));
	in_mlx(mlx);
	grid = malloc(sizeof(grid));
	ft_memset(&grid, 0, sizeof(grid));
	mlx->grid = grid;
	mlx->map = map;
	in_grid(mlx->grid, mlx->map);
}
