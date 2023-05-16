/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_image.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 11:04:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_IMAGE_H
# define STRUCTS_IMAGE_H

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
	char		**grid;

	int			map_y;
	int			map_x;

	int			screen_height;
	int			screen_width;

	int			pos_x;
	int			pos_y;

	double		dir_x;
	double		dir_y;

	double		plane_x;
	double		plane_y;

	double		camera_x;
	double		camera_y;

	t_vector	*vec;
}	t_grid;

typedef struct s_mlx
{
	void	*init;
	void	*img_win;

	char	*img_addr;
	int		*bits_per_pixel;
	int		*line_length;
	int		*endian;

	t_grid	*grid;
}	t_mlx;

#endif