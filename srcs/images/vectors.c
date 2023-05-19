/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:19:22 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/19 19:04:01 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	step_comp_calc(t_grid	*grid, t_vector	*vec)
{
	if (vec->raydir_x < 0)
	{
		vec->step_x = -1;
		vec->sidedist_x = (grid->pos_x - grid->map_x) * vec->deltadist_x;
	}
	else
	{
		vec->step_x = 1;
		vec->sidedist_x = (grid->map_x + 1 - grid->pos_x) * vec->deltadist_x;
	}
	printf("SideDistX -> [((%d + 1) - %f) * %f]", grid->map_x, grid->pos_x, vec->deltadist_x);
	if (vec->raydir_y < 0)
	{
		vec->step_y = -1;
		vec->sidedist_y = (grid->pos_y - grid->map_y) * vec->deltadist_y;
	}
	else
	{
		vec->step_y = 1;
		vec->sidedist_y = (grid->map_y + 1.0 - (int)grid->pos_y) * vec->deltadist_y;
	}
	printf("sideDistX -> [%d]\n", grid->map_x - grid->pos_x);
	printf("sideDistY -> [%d]\n", grid->map_y - grid->pos_y);
	//printf("sideDistX -> [%f]\n", vec->sidedist_x);
	//printf("sideDistY -> [%f]\n", vec->sidedist_y);
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
			grid->pos_x += vec->step_x;
			flag = 0;
		}
		else
		{
			vec->sidedist_y += vec->deltadist_y;
			grid->pos_y += vec->step_y;
			flag = 1;
		}
	}
	return (flag);
}

void	init_ray_dis(t_grid	*grid, double x, t_vector	*vec)
{
	grid->camera_x = (2 * (x / (grid->screen_width))) - 1;
	printf("rayDir-X -> [(%f + %f) * %f]\n", grid->dir_x, grid->plane_x, grid->camera_x);
	printf("rayDir-Y -> [(%f + %f) * %f]\n", grid->dir_y, grid->plane_y, grid->camera_x);
	vec->raydir_x = (grid->dir_x + grid->plane_x) * grid->camera_x;
	vec->raydir_y = (grid->dir_y + grid->plane_y) * grid->camera_x;
	vec->deltadist_x = (1 / vec->raydir_x);
	vec->deltadist_y = (1 / vec->raydir_y);
	if (vec->deltadist_x < 0)
		vec->deltadist_x *= (double)-1;
	if (vec->deltadist_y < 0)
		vec->deltadist_y *= (double)-1;
	printf("deltaDistX -> [%f]\n", vec->deltadist_x);
	printf("deltaDistY -> [%f]\n", vec->deltadist_y);
}
