/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/05 10:09:43 by jaizpuru         ###   ########.fr       */
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

	int	dirX; // initial pos of Direction Vector
	int	dirY;

	int	planeX; // Camera Vector
	int	planeY;
	
	// Unitary Double Variables

	double	u_mapHeight; // 2d grid
	double	u_mapWidth;

	double	u_screenHeight; // minilibX-image
	double	u_screenWidth;

	double	u_posX; // starting pos of character & Pos Vector
	double	u_posY;

	double	u_dirX; // initial pos of Direction Vector
	double	u_dirY;

	double	u_planeX; // Camera Vector
	double	u_planeY;
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