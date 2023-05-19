/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/19 19:06:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	crt_image(double x, t_in *in, t_grid *grid)
{
	in->grid->map_x = (int)in->grid->pos_x;
	in->grid->map_y = (int)in->grid->pos_y;
	init_ray_dis(grid, x, grid->vec);// works perfectly fine
	step_comp_calc(grid, grid->vec);
	grid->vec->axe = get_wall(in->map, grid, grid->vec);
	if (!grid->vec->axe)
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_x) - grid->vec->deltadist_x);
	else
		grid->vec->short_wall_dist
			= ((grid->vec->sidedist_y) - grid->vec->deltadist_y);
	get_height(grid, grid->vec, grid->vec->c);
	draw_ver_line(x, in, grid, grid->vec->c);
	printf("after_grid->posX -> [%f]\n", grid->pos_x);
	printf("after_grid->posY -> [%f]\n", grid->pos_y);
}

void	init_image(t_in	*in)
{
	double	x;

	x = (double)0;
	while (x++ <= in->grid->screen_width)
	{
		crt_image(x, in, in->grid);
		in->grid->pos_x = in->map->x;
		in->grid->pos_y = in->map->y;
	}
}
