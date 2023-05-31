/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/31 12:34:24 by jaizpuru         ###   ########.fr       */
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

void	redraw_texture(t_in *in, t_grid *grid, t_colors *c)
{
	c->text_num = in->map->map[grid->map_y][grid->map_x] - 1;
	if (grid->vec->axe == 1)
		c->wall_hit = (grid->pos_y)
			* (grid->vec->short_wall_dist * grid->vec->raydir_y);
	else
		c->wall_hit = (grid->pos_x)
			* (grid->vec->short_wall_dist * grid->vec->raydir_x);
	c->wall_hit -= floor(c->wall_hit);
	in->xpm = mlx_load_xpm42(trim_dir(in->map->no));
	c->text_coord = c->wall_hit * (c->text_width);
	if (grid->vec->axe == 0 && grid->vec->raydir_x > 0.)
		c->text_coord = c->text_width - c->text_coord - 1;
	if (grid->vec->axe == 1 && grid->vec->raydir_y < 0.)
		c->text_coord = c->text_width - c->text_coord - 1;
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
