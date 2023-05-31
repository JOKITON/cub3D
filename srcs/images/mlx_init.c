/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/31 12:33:30 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	in_dir(t_grid *grid, t_map *map)
{
	if (map->typ == 'N')
	{
		grid->dir_y = 1.;
		grid->plane_x = 0.66;
	}
	else if (map->typ == 'W')
	{
		grid->dir_x = -1.;
		grid->plane_y = -0.66;
	}
	else if (map->typ == 'E')
	{
		grid->dir_x = 1.;
		grid->plane_y = 0.66;
	}
	else if (map->typ == 'S')
	{
		grid->dir_y = -1.;
		grid->plane_x = -0.66;
	}
}

void	in_grid(t_grid	*grid, t_map *map)
{
	grid->vec = malloc(sizeof(t_vector));
	ft_memset(grid->vec, 0, sizeof(t_vector));
	grid->vec->c = malloc(sizeof(t_colors));
	ft_memset(grid->vec->c, 0, sizeof(t_colors));
	grid->screen_height = 1080;
	grid->screen_width = 1920;
	in_dir(grid, map);
	grid->pos_x = map->x - 1;
	grid->pos_y = map->y - 1;
	map->x -= 1;
	map->y -= 1;
}

void	in_mlx(t_in	*in)
{
	in->mlx_t = mlx_init(1920, 1080, "cub3D", true);
	in->img = mlx_new_image(in->mlx_t, 1920, 1080);
}

void	in_structs(t_in *in)
{
	in->mlx_t = malloc(sizeof(mlx_t));
	ft_memset(in->mlx_t, 0, sizeof(mlx_t));
	in->img = malloc(sizeof(mlx_image_t));
	in_mlx(in);
	in->grid = malloc(sizeof(t_grid));
	ft_memset(in->grid, 0, sizeof(t_grid));
	in_grid(in->grid, in->map);
	in->time = malloc(sizeof(t_time));
	ft_memset(in->time, 0, sizeof(t_time));
	in->xpm = malloc(sizeof(xpm_t));
}
