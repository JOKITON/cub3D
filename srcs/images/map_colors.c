/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/03 13:45:29 by jaizpuru         ###   ########.fr       */
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
		c->wall_color = 0xFFFFF0;
	else
		c->wall_color = 0xF0FFF0;
}

void	draw_ver_line(int x, t_in	*in, t_grid	*grid, t_colors	*c)
{
	int	y;

	y = 0;
	while (y++ <= grid->screen_height)
	{
		if (y <= c->color_bstart)
			mlx_put_pixel(in->img, x, y, 0xA8A495);
		else if (y > c->color_bstart && y < c->color_bend)
			mlx_put_pixel(in->img, x, y, c->wall_color);
		else if (y >= c->color_bend)
			mlx_put_pixel(in->img, x, y, 0x556B2F);
	}
}
