/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/23 11:50:08 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	crt_image(double x, t_in *in, t_grid *grid)
{
	grid->map_x = (int)grid->pos_x;
	grid->map_y = (int)grid->pos_y;
	init_ray_dis(grid, x, grid->vec);
	step_comp_calc(grid, grid->vec);
	grid->vec->axe = get_wall(in->map, grid, grid->vec);
	if (grid->vec->axe == 0)
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_x) - grid->vec->deltadist_x);
	else
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_y) - grid->vec->deltadist_y);
	printf("PerpDistWallCalcX -> [%f] = [%f - %f]\n", grid->vec->short_wall_dist, grid->vec->sidedist_x, grid->vec->deltadist_x);
	printf("PerpDistWallCalcY -> [%f] = [%f - %f]\n", grid->vec->short_wall_dist, grid->vec->sidedist_y, grid->vec->deltadist_y);
	get_height(grid, grid->vec, grid->vec->c);
	draw_ver_line((int)x, in, grid, grid->vec->c);
}

void	init_image(t_in	*in)
{
	double	x;

	x = (double)0;
	while (x++ <= (in->grid->screen_width))
	{
		crt_image(x, in, in->grid);
	}
}
