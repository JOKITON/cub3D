/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:34:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/10 11:54:18 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	free_program(t_in	*in)
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
	mlx_destroy_window(in->mlx->init, in->mlx->win);
	exit (EXIT_SUCCESS);
}

int	keyhook(int keydata, t_in	*in)
{
	if (keydata == MAIN_ESC)
		free_program(in);
	else if (keydata == W_KEY)
		move_front(in);
	else if (keydata == S_KEY)
		move_back(in);
	else if (keydata == A_KEY)
		move_left(in);
	else if (keydata == D_KEY)
		move_right(in);
	else if (keydata == ARROW_LEFT)
		move_cam_left(in);
	else if (keydata == ARROW_RIGHT)
		move_cam_right(in);
	else if (keydata == KEY_1)
		change_floor_color(in);
	else if (keydata == KEY_2)
		change_ceiling_color(in);
	else
		return ;
	init_image(in);
	mlx_put_image_to_window(in->mlx->init, in->mlx->win, in->mlx->img->img, 0, 0);
}

void	get_hooks(t_in	*in)
{
	mlx_hook(in->mlx->win, 2, 1L << 0, keyhook, in);
	mlx_hook(in->mlx->win, 17, 0, free_program, in);
}
