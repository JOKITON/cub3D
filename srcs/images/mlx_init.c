/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/09 16:25:43 by jaizpuru         ###   ########.fr       */
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

void	*load_xpm(t_in	*in, int *ar, char	*dir)
{
	void		*img;

	img = mlx_xpm_file_to_image(in->mlx->init, dir, NULL, NULL);
	ar = (int *)mlx_get_data_addr(img,
			NULL, NULL, NULL);
	return (img);
}

void	in_mlx(t_in	*in, t_mlx *mlx)
{
	in->mlx->init = mlx_init();
	in->mlx->win = mlx_new_window(in->mlx->init, WINDOW_WIDTH,
			WINDOW_HEIGHT, "cub3d");
	in->mlx->img->img = mlx_new_image(in->mlx->init,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	in->mlx->img->add = (int *)mlx_get_data_addr(in->mlx->img->img,
			&in->mlx->img->bits_ppixel,
			&in->mlx->img->line_length, &in->mlx->img->endian);
	if (!in->mlx->img->img)
		exit (EXIT_FAILURE);
	in->textures->img_north = load_xpm
		(in, &in->textures->add_north, trim_dir(in->map->no));
	in->textures->img_east = load_xpm
		(in, &in->textures->add_east, trim_dir(in->map->ea));
	in->textures->img_west = load_xpm
		(in, &in->textures->add_west, trim_dir(in->map->we));
	in->textures->img_south = load_xpm
		(in, &in->textures->add_south, trim_dir(in->map->so));
}

void	in_structs(t_in *in)
{
	in->mlx = malloc(sizeof(t_mlx));
	ft_memset(in->mlx, 0, sizeof(t_mlx));
	in->mlx->img = malloc(sizeof(t_img));
	ft_memset(in->mlx->img, 0, sizeof(t_img));
	in->textures = malloc(sizeof(t_text));
	ft_memset(in->textures, 0, sizeof(t_text));
	in_mlx(in, in->mlx);
	in->grid = malloc(sizeof(t_grid));
	ft_memset(in->grid, 0, sizeof(t_grid));
	in_grid(in->grid, in->map);
	in->time = malloc(sizeof(t_time));
	ft_memset(in->time, 0, sizeof(t_time));
}
