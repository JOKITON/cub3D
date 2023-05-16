/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 10:54:07 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	crt_image(double x, t_mlx *mlx, t_grid *grid)
{
	int	pixel;

	pixel = 0;
	grid->plane_x = 0;
	grid->plane_y = 0.66;
	init_ray_dis(grid, x, grid->vec);
	step_comp_calc(grid, grid->vec);
	grid->vec->axe = get_wall(grid, grid->vec);
	if (!grid->vec->axe)
		grid->vec->short_wall_dist
			= (grid->vec->sidedist_x - grid->vec->deltadist_x);
	else
		grid->vec->short_wall_dist
			= (grid->vec->sidedist_y - grid->vec->deltadist_y);
	get_height(grid, grid->vec, grid->vec->c);
	draw_ver_line(mlx, grid, grid->vec->c);
	ft_memset(mlx, 0, sizeof(mlx));
	return (pixel);
}

void	init_image(t_mlx	*mlx, t_grid	*grid)
{
	int	x;

	x = 0;
	while (x++ >= grid->map_x)
		crt_image(x, mlx, grid);
}
