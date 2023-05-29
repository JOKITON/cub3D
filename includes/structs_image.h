/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/29 11:50:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_IMAGE_H
# define STRUCTS_IMAGE_H

# include "structs_map.h"

typedef struct s_colors
{
	int	line_height;

	int	color_bstart;
	int	color_bend;

	int	color;
}	t_colors;

typedef struct s_vector
{
	double		raydir_x;
	double		raydir_y;

	double		sidedist_x;
	double		sidedist_y;

	double		deltadist_x;
	double		deltadist_y;

	int			step_x;
	int			step_y;

	double		short_wall_dist;
	int			axe;
	t_colors	*c;
}	t_vector;

typedef struct s_grid
{
	int			map_y;
	int			map_x;

	int			screen_height;
	int			screen_width;

	double		pos_x;
	double		pos_y;

	double		dir_x;
	double		dir_y;

	double		plane_x;
	double		plane_y;

	double		camera_x;
	double		camera_y;

	t_vector	*vec;
}	t_grid;

typedef struct s_time
{
	double		old_time;
	double		c_time;

	double		frame_rate;

	double		m_speed;
	double		r_speed;
}	t_time;

typedef struct s_in
{

	t_grid		*grid;
	t_map		*map;
	t_time		*time;
	mlx_t		*mlx_t;
	mlx_image_t	*img;
}	t_in;

#endif