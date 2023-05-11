/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 21:58:40 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_ver_line(t_mlx	*mlx, t_grid	*grid, t_colors	*c)
{
	int	y;
	int	x;

	y = 0;
	x = (((int)grid->cameraX / 2) - 1);
	while (y++ <= grid->screenHeight)
	{
		if (y <= c->drawStart)
			mlx->img_addr[(y * x) + x] = 0x00010000;
		else if (y > c->drawStart && y < c->drawEnd)
			mlx->img_addr[(y * x) + x] = c->color;
		else if (y >= c->drawEnd)
			mlx->img_addr[(y * x) + x] = 0x00625eef;
	}
}

void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c)
{
	vec->c->lineHeight = (int)(grid->screenHeight / vec->perpWallDist);
	c->drawStart = -(c->lineHeight) / 2 + grid->screenHeight / 2;
	if (c->drawStart < 0)
		c->drawStart = 0;
	c->drawEnd = c->lineHeight / 2 + grid->screenHeight / 2;
	if (c->drawEnd >= grid->screenHeight)
		c->drawEnd = grid->screenHeight - 1;
	if (vec->axe == 1)
		c->color = 0x00FF0000;
	else
		c->color = 0x000000FF;
}
