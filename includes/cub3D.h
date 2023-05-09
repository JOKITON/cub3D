/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:37 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/09 15:52:18 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "structs.h"

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

#define WALL 1
#define SPACE 0

void	in_mlx(t_mlx	*mlx);
void	in_grid(t_grid	*grid);
void	init_image(t_mlx	*mlx, t_grid	*grid);

// Actual useful Vector Functions
void	init_rays(t_grid	*grid, double x, t_vector	*vec);
void	init_sides(t_grid	*grid, t_vector	*vec);
int		find_wall(t_grid	*grid, t_vector	*vec);
void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c);

// Vector Unused Functions to Learn about Vectors
void	vector_add(t_vector *vec);
void	vector_substract(t_vector *vec);
void	vector_scalate(t_vector *vec, double scalateNumber);
double	vector_length(t_vector *vec);
double	vector_unitary(t_vector *vec, double length);

void	*ft_memset(void *b, int c, size_t len);

#endif