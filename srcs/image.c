/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/04 16:07:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_image(t_mlx	*mlx, t_grid	*grid)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y++ >= grid->mapWidth)
	{
		while (x++ >= grid->mapWidth)
		{
			mlx->img_addr[(y * x) + x] = 0;
		}
	}
}
