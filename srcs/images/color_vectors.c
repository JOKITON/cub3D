/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/17 11:16:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_ver_line(t_in	*in, t_grid	*grid, t_colors	*c)
{
	int	y;
	int	x;

	y = 0;
	x = (((int)grid->camera_x / 2) - 1);
	while (y++ <= grid->screen_height)
	{
		if (y <= c->color_bstart)
			in->mlx->img_addr[(y * x) + x] = 0x00010000;
		else if (y > c->color_bstart && y < c->color_bend)
			in->mlx->img_addr[(y * x) + x] = c->color;
		else if (y >= c->color_bend)
			in->mlx->img_addr[(y * x) + x] = 0x00625eef;
	}
}

void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c)
{
	vec->c->line_height = (int)(grid->screen_height / vec->short_wall_dist);
	c->color_bstart = -(c->line_height) / 2 + grid->screen_height / 2;
	if (c->color_bstart < 0)
		c->color_bstart = 0;
	c->color_bend = c->line_height / 2 + grid->screen_height / 2;
	if (c->color_bend >= grid->screen_height)
		c->color_bend = grid->screen_height - 1;
	if (vec->axe == 1)
		c->color = 0x00FF0000;
	else
		c->color = 0x000000FF;
}
