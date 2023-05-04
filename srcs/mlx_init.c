/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:50:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/04 16:07:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	in_mlx(t_mlx	*mlx)
{
	mlx_init(&mlx->init);
	mlx_new_window(&mlx->init, 1920, 1080, "cub3D");
	mlx->img_win = mlx_new_image(&mlx->init, 1920, 1080);
	mlx->img_addr = mlx_get_data_addr(&mlx->init,
			mlx->bits_per_pixel, mlx->line_length, mlx->endian);
}

