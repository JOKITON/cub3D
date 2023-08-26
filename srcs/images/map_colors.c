/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/26 20:20:40 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c)
{
	vec->c->line_height = (int)(grid->screen_height / vec->short_wall_dist);
	c->color_bstart = (-(c->line_height) / 2) + grid->screen_height / 2;
	if (c->color_bstart < 0)
		c->color_bstart = 0;
	c->color_bend = c->line_height / 2 + grid->screen_height / 2;
	if (c->color_bend >= grid->screen_height)
		c->color_bend = grid->screen_height - 1;
	if (vec->axe == 1)
		c->wall_color = 0x00FFFFF0;
	else
		c->wall_color = 0x00F0FFF0;
}

void	draw_ver_line(int x, t_in	*in, t_grid	*grid, t_colors	*c)
{
	int			y;

	y = 0;
	if (!c->ceiling_color || !c->floor_color)
	{
		change_ceiling_color(in);
		change_floor_color(in);
	}
	while (y < grid->screen_height)
	{
		if (y <= c->color_bstart)
			in->mlx->img->add[((y * WINDOW_WIDTH) + x)] = c->floor_color;
		else if (y > c->color_bstart && y < c->color_bend)
			in->mlx->img->add[((y * WINDOW_WIDTH) + x)] = c->wall_color;
		else if (y >= c->color_bend)
			in->mlx->img->add[((y * WINDOW_WIDTH) + x)] = c->ceiling_color;
		y++;
	}
}
