/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/07 11:39:51 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_IMAGE_H
# define STRUCTS_IMAGE_H

# include "structs_map.h"

typedef struct s_colors
{
	int		line_height;

	int		color_bstart;
	int		color_bend;

	uint32_t	wall_color;
	int			text_num;

	double		wall_hit;
	int		text_x;
	int		text_y;
	int		text_width;

	double	step;
	double	text_pos;
}	t_colors;

typedef struct s_vector
{
	float		raydir_x;
	float		raydir_y;

	float		sidedist_x;
	float		sidedist_y;

	float		deltadist_x;
	float		deltadist_y;

	int			step_x;
	int			step_y;

	float		short_wall_dist;
	int			axe;
	t_colors	*c;
}	t_vector;

typedef struct s_grid
{
	int			or_x;

	int			map_y;
	int			map_x;

	int			screen_height;
	int			screen_width;

	float		pos_x;
	float		pos_y;

	float		dir_x;
	float		dir_y;

	float		plane_x;
	float		plane_y;

	float		camera_x;
	float		camera_y;

	t_vector	*vec;
}	t_grid;

typedef struct s_time
{
	float		old_time;
	float		c_time;

	float		frame_rate;

	float		m_speed;
	float		r_speed;
}	t_time;

typedef struct s_text
{
	int			*texture;
	mlx_image_t	*img_north;
	mlx_image_t	*img_east;
	mlx_image_t	*img_west;
	mlx_image_t	*img_south;
}	t_text;

typedef struct s_in
{

	t_grid			*grid;
	t_map			*map;
	t_time			*time;
	mlx_t			*mlx_t;
	mlx_image_t		*img;
	t_text			*textures;
	xpm_t			*xpm;
}	t_in;

#endif