/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/29 12:12:37 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*void	print_math(t_in	*in, t_grid	*grid)
{
	printf("\n	////////////////PRINT_MATH////////////////\n");
	printf("\n			_INIT_DATA_:\n");
	printf("\n	   DIR -> {%c}\n", in->map->typ);
	printf("	 POS_X -> {%f}\n", in->grid->pos_x);
	printf("	 POS_Y -> {%f}\n", in->grid->pos_y);
	printf("	X_Axys -> {%f}\n\n", in->grid->camera_x);

	printf("			_VECTORS_:\n\n");
	printf("	RayDir-X :\n [%f + (%f * %f)] == {%f}\n", grid->dir_x,
		grid->plane_x, grid->camera_x, grid->vec->raydir_x);
	printf("	RayDir-Y :\n [%f + (%f * %f)] == {%f}\n\n", grid->dir_y,
		grid->plane_y, grid->camera_x, grid->vec->raydir_y);
	printf("	DeltaDistX :\n [1 / %f] == {%f}\n",
		grid->vec->raydir_x, grid->vec->deltadist_x);
	printf("	DeltaDistY :\n [1 / %f] == {%f}\n\n",
		grid->vec->raydir_y, grid->vec->deltadist_y);
	printf("	SideDistX :\n [((%d + (1)) - %f) * %f] == {%f}\n", grid->map_x,
		grid->pos_x, grid->vec->deltadist_x, grid->vec->sidedist_x);
	printf("	SideDistY :\n [((%d + (1)) - %f) * %f] == {%f}\n\n", grid->map_y,
		grid->pos_y, grid->vec->deltadist_y, grid->vec->sidedist_y);
	printf("	Final_Ray_Dest_:	{%d, %d}\n\n",
		grid->map_x, grid->map_y);
	if (grid->vec->axe == 0)
		printf("	[X_PerpDistWallCalcX -> [%f - %f] == {%f}]\n",
			grid->vec->sidedist_x, grid->vec->deltadist_x,
			grid->vec->short_wall_dist);
	else
		printf("	[Y_PerpDistWallCalc -> [%f - %f] == {%f}]\n",
			grid->vec->sidedist_y, grid->vec->deltadist_y,
			grid->vec->short_wall_dist);

	printf("\n			_IMAGE_RELATED_:\n\n	Line_Height_: {%d}\n",
		grid->vec->c->line_height);
	printf("	Color_Start -> {%d}\n", grid->vec->c->color_bstart);
	printf("	Color_End -> {%d}\n", grid->vec->c->color_bend);
	printf("	---------------------------------------------\n");
}*/

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
	get_height(grid, grid->vec, grid->vec->c);
	//print_math(in, grid);
	draw_ver_line((int)x, in, grid, grid->vec->c);
	in->time->old_time = in->time->c_time;
	in->time->c_time += 30;
	in->time->frame_rate = (in->time->c_time - in->time->old_time) / 1000.;
	in->time->m_speed = in->time->frame_rate * 8.;
	in->time->r_speed = in->time->frame_rate * 3.;
}

void	init_image(t_in	*in)
{
	double	x;

	x = 0.;
	while (x++ <= (in->grid->screen_width))
		crt_image(x, in, in->grid);
}
