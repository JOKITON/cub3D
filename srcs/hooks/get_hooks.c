/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:34:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/30 15:43:45 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_program(t_in	*in)
{
	int	i;

	i = 0;
	while (in->map->map && in->map->map[i])
	{
		free(in->map->map[i]);
		if (in->map->star && in->map->star[i])
			free(in->map->star[i]);
		if (in->map->file && in->map->file[i])
			free(in->map->file[i]);
		i++;
	}
	free(in->map->map);
	free(in->map->star);
	free(in->map->file);
	free(in->map);
	free(in);
	exit (EXIT_SUCCESS);
}

void	keyhook(mlx_key_data_t keydata, t_in	*in)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		free_program(in);
	else if (keydata.key == MLX_KEY_W)
		move_front(in);
	else if (keydata.key == MLX_KEY_S)
		move_back(in);
	else if (keydata.key == MLX_KEY_A)
		move_left(in);
	else if (keydata.key == MLX_KEY_D)
		move_right(in);
	else if (keydata.key == MLX_KEY_LEFT)
		move_cam_left(in);
	else if (keydata.key == MLX_KEY_RIGHT)
		move_cam_right(in);
	else
		return ;
/* 	printf("DirX -> {%f}\n", in->grid->dir_x);
	printf("DirY -> {%f}\n", in->grid->dir_y); */
	init_image(in);
	if (!in->img || (mlx_image_to_window(in->mlx_t, in->img, 0, 0) < 0))
		exit(EXIT_FAILURE);
}

void	get_hooks(t_in	*in)
{
	mlx_key_hook(in->mlx_t, &keyhook, in);
}
