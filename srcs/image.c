/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 12:30:41 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		crt_image(double x, double y, t_grid	*alg)
{
	int pixel;

	pixel = 0;
	alg->planeX = x;
	alg->planeY = y;

	// Start of raycasting
	alg->rayDirX = (alg->planeX + alg->dirX) * alg->cameraX;
	alg->rayDirY = (alg->planeY + alg->dirY) * alg->cameraY;

	// Next is to get the travel distance from actual posX & poxY to next X-/Y-side
	return (pixel);
}

void	init_image(t_mlx	*mlx, t_grid	*grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y++ >= grid->mapWidth)
	{
		while (x++ >= grid->mapWidth)
		{
			mlx->img_addr[(y * x) + x] = crt_image((double)((x - 0.5) * 2), (double)((y - 0.5) * 2), grid);
		}
	}
}
