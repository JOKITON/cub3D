/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:37 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/08 12:11:34 by jaizpuru         ###   ########.fr       */
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

void	in_mlx(t_mlx	*mlx);
void	init_image(t_mlx	*mlx, t_grid	*grid);

// VECTORS
void	vector_add(t_vector *vec);
void	vector_substract(t_vector *vec);
void	vector_scalate(t_vector *vec, double scalateNumber);
double	vector_length(t_vector *vec);
double	vector_unitary(t_vector *vec, double length);

#endif