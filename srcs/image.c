/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 13:30:06 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		crt_image(double x, double y, t_grid	*alg)
{
	int pixel;

	pixel = 0;
	alg->planeX = x;
	alg->planeY = y;

	init_rays(alg);
	init_sides(alg);
	find_wall(alg);
	return (pixel);
}

void	init_image(t_mlx	*mlx, t_grid	*grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y++ >= grid->mapY)
	{
		while (x++ >= grid->mapX)
		{
			mlx->img_addr[(y * x) + x] = crt_image((double)((x - 0.5) * 2), (double)((y - 0.5) * 2), grid);
		}
	}
}
