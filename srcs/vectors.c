/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:19:22 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 13:29:39 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_sides(t_grid	*grid)
{
	if (grid->vec->rayDirX < 0)
	{
		grid->vec->stepX = -1;
		grid->vec->sideDistX = (grid->posX - grid->mapX) * grid->vec->deltaDisX;
	}
	else
	{
		grid->vec->stepX = 1;
		grid->vec->sideDistX = (grid->mapX + 1.0 - grid->posX) * grid->vec->deltaDisX;
	}
	if (grid->vec->rayDirY < 0)
	{
		grid->vec->stepY = -1;
		grid->vec->sideDistY = (grid->posY - grid->mapY) * grid->vec->deltaDisY;
	}
	else
	{
		grid->vec->stepY = 1;
		grid->vec->sideDistY = (grid->mapY + 1.0 - grid->posY) * grid->vec->deltaDisY;
	}
}

void	find_wall(t_grid	*alg)
{
	int	flag;

	flag = 0;
	while(alg->grid[alg->mapY][alg->mapX] != WALL)
	{
		if (alg->vec->sideDistX < alg->vec->sideDistY)
        {
          alg->vec->sideDistX += alg->vec->deltaDisX;
          alg->mapX += alg->vec->stepX;
          flag = 0;
        }
        else
        {
          alg->vec->sideDistY += alg->vec->deltaDisY;
          alg->mapY += alg->vec->stepY;
          flag = 1;
        }
	}
}

void	init_rays(t_grid	*alg)
{
	alg->vec->rayDirX = (alg->planeX + alg->dirX) * alg->cameraX;
	alg->vec->rayDirY = (alg->planeY + alg->dirY) * alg->cameraY;

	// Travel distance from actual posX & poxY to next X-/Y-side
	alg->vec->deltaDisX = abs(1 / alg->vec->rayDirX);
	alg->vec->deltaDisY = abs(1 / alg->vec->rayDirY);
}
