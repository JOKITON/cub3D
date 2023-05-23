/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:19:22 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/23 14:27:01 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	step_comp_calc(t_grid	*grid, t_vector	*vec)
{
	if (vec->raydir_x < 0.)
	{
		vec->step_x = -1;
		vec->sidedist_x = (grid->pos_x - grid->map_x) * vec->deltadist_x;
	}
	else
	{
		vec->step_x = 1;
		vec->sidedist_x = (grid->map_x + 1. - grid->pos_x) * vec->deltadist_x;
	}
	if (vec->raydir_y < 0.)
	{
		vec->step_y = -1;
		vec->sidedist_y = (grid->pos_y - grid->map_y) * vec->deltadist_y;
	}
	else
	{
		vec->step_y = 1;
		vec->sidedist_y = (grid->map_y + 1.0 - grid->pos_y) * vec->deltadist_y;
	}
	//printf("2. Step: Calc_SideDistX -> [%f] = [((%d + 1) - %f) * %f]\n", vec->sidedist_x, grid->map_x, grid->pos_x, vec->deltadist_x);
	//printf("2. Step: Calc_SideDistY -> [%f] = [((%d + 1) - %f) * %f]\n", vec->sidedist_y, grid->map_y, grid->pos_y, vec->deltadist_y);
}

int	get_wall(t_map *map, t_grid	*grid, t_vector	*vec)
{
	int	flag;

	flag = 0;
	while (map->map[grid->map_y][grid->map_x] != '1')
	{
		if (vec->sidedist_x < vec->sidedist_y)
		{
			vec->sidedist_x += vec->deltadist_x;
			grid->map_x += vec->step_x;
			flag = 0;
			//printf("step on X[%f] -> [%f]\n", grid->camera_x, vec->deltadist_x);
		}
		else
		{
			vec->sidedist_y += vec->deltadist_y;
			grid->map_y += vec->step_y;
			flag = 1;
			//printf("step on Y[%f] -> [%f]\n", grid->camera_x, vec->deltadist_y);
		}
	}
	//printf("3. Step: grid->map_y -> [%d]\ngrid->map_x -> [%d]\n", grid->map_y, grid->map_x);
	return (flag);
}

void	init_ray_dis(t_grid	*grid, double x, t_vector	*vec)
{
	grid->camera_x = (2 * (x / (grid->screen_width))) - 1;
	//printf("Calc_rayDir-X -> [(%f + %f) * %f]\n", grid->dir_x, grid->plane_x, grid->camera_x);
	//printf("Calc_rayDir-Y -> [(%f + %f) * %f]\n", grid->dir_y, grid->plane_y, grid->camera_x);
	vec->raydir_x = grid->dir_x + (grid->plane_x * (grid->camera_x));
	vec->raydir_y = grid->dir_y + (grid->plane_y * (grid->camera_x));
	//printf("RaydirX -> [%f]\n", vec->raydir_x);
	//printf("RaydirY -> [%f]\n", vec->raydir_y);
	vec->deltadist_x = fabs(1 / vec->raydir_x);
	vec->deltadist_y = fabs(1 / vec->raydir_y);
	//printf("deltaDistX -> [%f]\n", vec->deltadist_x);
	//printf("deltaDistY -> [%f]\n", vec->deltadist_y);
}
