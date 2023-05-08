/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 12:24:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_vector
{
	double x; // x axis
	double y; // y axis
	double z; // z axis
}	t_vector;

typedef struct s_grid
{
	char	**grid;

	int	mapHeight; // 2d grid
	int	mapWidth;

	int	screenHeight; // minilibX-image
	int	screenWidth;

	int	posX; // starting pos of character & Pos Vector
	int	posY;

	double	dirX; // initial pos of Direction Vector
	double	dirY;

	double	planeX; // Screen position
	double	planeY;

	double	cameraX;
	double	cameraY;

	double	rayDirX;
	double	rayDirY;
} t_grid;

typedef	struct s_mlx
{
	void	*init;
	void	*img_win;

	char	*img_addr;
	int		*bits_per_pixel;
	int		*line_length;
	int		*endian;
} t_mlx;

#endif