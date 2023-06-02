
#include "../../includes/cub3D.h"
#define TILE_SIZE 64

static int	calculate_texture_height_pixels(mlx_texture_t *texture, t_ray ray,
	int draw_height)
{
	int		height;
	float	height_divided;

	if (ray.wall_height > WINDOW_HEIGHT)
		draw_height += (ray.wall_height - WINDOW_HEIGHT) / 2;
	height_divided = texture->height / ray.wall_height;
	height = floor((height_divided * draw_height)) * texture->width;
	return (height);
}

static int	get_texture_pixel_color(mlx_texture_t *texture, t_ray ray,
	float current_height, int width_pixels)
{
	u_int8_t	*pixel;
	int			pixel_texture_location;

	pixel_texture_location = calculate_texture_height_pixels(texture, ray,
			current_height);
	pixel_texture_location += width_pixels;
	pixel_texture_location *= texture->bytes_per_pixel;
	pixel = &texture->pixels[pixel_texture_location];
	return (get_colour_from_pixel(pixel));
}

static int	calculate_texture_width_pixels(t_ray ray, int texture_width)
{
	float	width_pixels;

	if (ray.was_hit_horizontal)
		width_pixels = fmod(ray.horizontal_wall_hit.x, TILE_SIZE) / TILE_SIZE;
	else
		width_pixels = fmod(ray.vertical_wall_hit.y, TILE_SIZE) / TILE_SIZE;
	width_pixels *= texture_width;
	return (width_pixels);
}

void	draw_column(t_cub3d *cub3d, t_ray ray,
	struct mlx_texture *texture, int x)
{
	int		width;
	int		current_height;
	int		color;
	float	width_pixels;

	x = x * WALL_STRIP_WIDTH;
	width_pixels = calculate_texture_width_pixels(ray, texture->width);
	current_height = 0;
	while (ray.draw_start + current_height < ray.draw_end)
	{
		color = get_texture_pixel_color(texture, ray, current_height,
				width_pixels);
		width = 0;
		while (width < WALL_STRIP_WIDTH)
		{
			mlx_put_pixel(cub3d->images.walls, x + width,
				ray.draw_start + current_height, color);
			width++;
		}
		current_height++;
	}
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
	c->text_width = in->xpm->texture.width;
	c->text_x = c->wall_hit * (c->text_width);
	if (grid->vec->axe == 0 && grid->vec->raydir_x > 0.)
		c->text_x = c->text_width - c->text_x - 1;
	if (grid->vec->axe == 1 && grid->vec->raydir_y < 0.)
		c->text_x = c->text_width - c->text_x - 1;
	c->step = 1.0 * in->xpm->texture.height / c->line_height;
	c->text_pos = (c->color_bstart - grid->screen_height
			/ 2 + c->line_height / 2) * c->step;
	redraw(in, c);
}

void	redraw(t_in	*in, t_colors *c)
{
	int	y;

	in->img2 = mlx_texture_to_image(in->mlx_t, in->xpm);
	y = c->color_bstart;
	while (y >= c->color_bstart && y < c->color_bend)
	{
		c->text_y = (int)(c->text_pos) & (in->xpm->texture.height - 1);
		c->text_pos += c->step;
		in->img2->pixels
		//mlx_put_pixel(in->img, in->grid->or_x, y, in->xpm->color_count)
	}
}
