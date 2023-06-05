/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:46:40 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/05 12:40:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	redraw(t_in	*in, t_colors *c)
{
	int	y;

	y = c->color_bstart;
	while (y >= c->color_bstart && y < c->color_bend)
	{
		c->text_y = (int)(c->text_pos) & (TEX_HEIGHT - 1);
		c->text_pos += c->step;
		c->wall_color = in->textures->img_north->pixels
		[(int)((TEX_HEIGHT * c->text_y) + c->text_x)];
		if (in->grid->vec->axe == 1)
			c->wall_color = (c->wall_color >> 1) & 8355711;
		mlx_put_pixel(in->img, in->grid->or_x, y, c->wall_color);
		y++;
	}
}

void	redraw_texture(t_in *in, t_grid *grid, t_colors *c)
{
	if (grid->vec->axe == 0)
		c->wall_hit = (int)((grid->pos_y) + (grid->vec->short_wall_dist
					* grid->vec->raydir_y));
	else
		c->wall_hit = (int)((grid->pos_x) + (grid->vec->short_wall_dist
					* grid->vec->raydir_x));
	c->wall_hit -= floor(c->wall_hit);
	c->text_width = (int)TEX_HEIGHT;
	c->text_x = c->wall_hit * (c->text_width);
	if (grid->vec->axe == 0 && grid->vec->raydir_x > 0.)
		c->text_x = TEX_WIDTH - c->text_x - 1;
	if (grid->vec->axe == 1 && grid->vec->raydir_y < 0.)
		c->text_x = TEX_WIDTH - c->text_x - 1;
	c->step = 1.0 * TEX_HEIGHT / c->line_height;
	c->text_pos = (c->color_bstart - grid->screen_height
			/ 2 + c->line_height / 2) * c->step;
	redraw(in, c);
}
