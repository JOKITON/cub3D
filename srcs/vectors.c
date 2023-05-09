/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:19:22 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/09 15:33:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_sides(t_grid	*grid, t_vector	*vec)
{
	if (vec->rayDirX < 0)
	{
		vec->stepX = -1;
		vec->sideDistX = (grid->posX - grid->mapX) * vec->deltaDisX;
	}
	else
	{
		vec->stepX = 1;
		vec->sideDistX = (grid->mapX + 1.0 - grid->posX) * vec->deltaDisX;
	}
	if (vec->rayDirY < 0)
	{
		vec->stepY = -1;
		vec->sideDistY = (grid->posY - grid->mapY) * vec->deltaDisY;
	}
	else
	{
		vec->stepY = 1;
		vec->sideDistY = (grid->mapY + 1.0 - grid->posY) * vec->deltaDisY;
	}
}

int	find_wall(t_grid	*grid, t_vector	*vec)
{
	int	flag;

	flag = 0;
	while(grid->grid[grid->mapY][grid->mapX] != (int)WALL) // use [char*] or [int]
	{
		if (vec->sideDistX < vec->sideDistY)
        {
          vec->sideDistX += vec->deltaDisX;
          grid->mapX += vec->stepX;
          flag = 0;
        }
        else
        {
          vec->sideDistY += vec->deltaDisY;
          grid->mapY += vec->stepY;
          flag = 1;
        }
	}
	return (flag); // if (flag)-> Y_side, else -> X_side
}

void	init_rays(t_grid	*grid, double x, t_vector	*vec)
{
	grid->cameraX = 2 * x / grid->screenWidth - 1;
	vec->rayDirX = (grid->planeX + grid->dirX) * grid->cameraX;
	vec->rayDirY = (grid->planeY + grid->dirY) * grid->cameraX;

	// Travel distance from actual posX & poxY to next X-/Y-side
	vec->deltaDisX = abs(1 / vec->rayDirX);
	vec->deltaDisY = abs(1 / vec->rayDirY);
}
