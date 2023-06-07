/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:46:40 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/07 23:06:02 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	int	ret;

	ret = (r << 24) | (g << 16) | (b << 8) | (a);
	return (ret);
}

int	get_rgba_pieces(uint8_t	*ar, int pos)
{
	return (get_rgba(ar[pos], ar[pos + 1], ar[pos + 2], ar[pos + 3]));
}

void	get_color(t_text *textures, t_in *in, t_colors *c)
{
	if (in->grid->vec->axe == 1)
	{
		if (in->grid->vec->step_y > 0.)
			c->wall_color = get_rgba_pieces(in->textures->img_north->pixels,
					(int)(TEX_HEIGHT * c->text_y + c->text_x) * BPP);
		if (in->grid->vec->step_y < 0.)
			c->wall_color = get_rgba_pieces(in->textures->img_south->pixels,
					(int)(TEX_HEIGHT * c->text_y + c->text_x) * BPP);
	}
	if (in->grid->vec->axe == 0)
	{
		if (in->grid->vec->step_x >= 0.)
			c->wall_color = get_rgba_pieces(in->textures->img_east->pixels,
					(int)(TEX_HEIGHT * c->text_y + c->text_x) * BPP);
		if (in->grid->vec->step_x < 0.)
			c->wall_color = get_rgba_pieces(in->textures->img_west->pixels,
					(int)(TEX_HEIGHT * c->text_y + c->text_x) * BPP);
	}
}

void	redraw(t_in	*in, t_colors *c)
{
	int		y;
	uint8_t	*pixel;

	y = c->color_bstart;
	while (y >= c->color_bstart && y < c->color_bend)
	{
		pixel = &in->img->pixels[(y * in->img->width + in->grid->or_x) * BPP];
		c->text_y = (int)(c->text_pos) & (TEX_HEIGHT - 1);
		c->text_pos += c->step;
		get_color(in->textures, in, c);
		mlx_draw_pixel(pixel, c->wall_color);
		y++;
	}
}

void	redraw_texture(t_in *in, t_grid *grid, t_colors *c)
{
	if (grid->vec->axe == 0)
		c->wall_hit = ((grid->pos_y) + (grid->vec->short_wall_dist
					* grid->vec->raydir_y));
	else
		c->wall_hit = ((grid->pos_x) + (grid->vec->short_wall_dist
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
