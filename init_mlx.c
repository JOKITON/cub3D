/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:23:45 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/01 16:33:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_mlx	*mlx)
{
	mlx = memset(mlx, 0, sizeof(*mlx));
	mlx->init = mlx_init();
	mlx_new_window(mlx->init, 1920, 1080, "cub3D");
	if (!(mlx->img = mlx_new_image(mlx->init, 1920, 1080)))
		return (perror("Image was not created succesfully"));
}