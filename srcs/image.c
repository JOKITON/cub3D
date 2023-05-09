/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/09 15:53:14 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		crt_image(double x, t_mlx	*mlx, t_grid	*grid)
{
	int pixel;

	pixel = 0;
	grid->planeX = 0;
	grid->planeY = 0.66;

	init_rays(grid, x, grid->vec);
	init_sides(grid, grid->vec);
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(!find_wall(grid, grid->vec))
		grid->vec->perpWallDist = (grid->vec->sideDistX - grid->vec->deltaDisX);
	else
		grid->vec->perpWallDist = (grid->vec->sideDistY - grid->vec->deltaDisY);
	get_height(grid, grid->vec, grid->vec->c);
	ft_memset(mlx, 0, sizeof(mlx));
	return (pixel);
}

void	init_image(t_mlx	*mlx, t_grid	*grid)
{
	int	x;

	x = 0;
	while (x++ >= grid->mapX)
		crt_image((double)((x - 0.5) * 2), mlx, grid);
}
