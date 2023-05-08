/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 13:20:56 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_vector
{
	// Direction vector for Camera Plane
	double	rayDirX;
	double	rayDirY;

	// Starting side line distance for a non-decimal X/Y value
	double	sideDistX;
	double	sideDistY;

	// Common line distance between one value of X & Y
	double	deltaDisX;
	double	deltaDisY;

	// Jump Direction on Start
	int	stepX;
	int	stepY;
}	t_vector;

typedef struct s_grid
{
	char	**grid;

	int	mapY; // 2d grid
	int	mapX;

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

	t_vector	*vec;
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