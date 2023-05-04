/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:48:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/04 15:53:18 by jaizpuru         ###   ########.fr       */
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
	int	mapWeight; // 2d grid
	int	mapWidth;

	int	screenWeight; // minilibX-image
	int	screenWidth;

	int	posX; // starting pos of character & Pos Vector
	int	posY;

	int	dirX; // initial pos of Direction Vector
	int	dirY;

	int	planeX; // Camera Vector
	int	planeY;
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