/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/05 11:34:53 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	steps_until_wall(t_grid	*alg) //  I need to do the same, but with a (-0.5, 0.5) margin
{
	int	dirY;
	int	dirX;
	int	length;

	dirY = alg->dirY;
	dirX = alg->dirX;
	while (!alg->grid[(alg->mapHeight - alg->posY) + dirY][alg->posX + dirX])
	{
		if (dirY != 0)
			dirY = dirY + dirY;
		if (dirX != 0)
			dirX = dirX + dirX;
	}
	length = (int)(fabs((double)dirX) + fabs((double)dirY));
	return (length);
}

double	get_screen_wall(double p_x, double p_y, t_grid	*alg) //  I need to do the same, but with a (-0.5, 0.5) margin
{
	double	x_length;
	double	y_length;

	init_unitary(alg);
	while (!alg->grid[alg->screenHeight - ((int)y_length * alg->screenHeight)][(int)x_length * alg->screenWidth])
	{
		if (p_x != 0)
			y_length += (p_y) + ((alg->u_dirX / alg->screenWidth) + (alg->u_dirY / alg->screenHeight)); // camera vector for X axis
		if (p_y != 0)
			x_length += (p_x) + ((alg->u_dirX / alg->screenWidth) + (alg->u_dirY / alg->screenHeight)); // camera vector for Y axis
	}
	return (y_length + x_length);
}

int		crt_image(double x, double y, t_grid	*alg)
{
	int	ret;
	// Parameter values are from (-0.5, 0.5)
		// Depending on the range of these values, I can get the camera plane 3D

		// I need to cast a ray to know where the walls are
			// I can know where the position vector is by just getting the grid structure, 2D
			
			// I suposse the direction vector helps us determine wich way we are going to see, so its 2D
	// Position vector is constant at start, as well as direction vector

	// I need to have unitary vectors, then add concret values to find walls.
	alg->planeX = x;
	alg->planeY = y;
	ret = get_screen_wall(x, y, alg); //alg->planeX, alg->planeY, alg->dirX, alg->dirY, alg->posX, alg->posY
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
			mlx->img_addr[(y * x) + x] = 0; // ((x / grid->mapWidth) - 0.5), ((y / grid->mapHeight) - 0.5)
		}
	}
}
