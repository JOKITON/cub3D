/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:38:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/09 15:52:01 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c)
{
	vec->c->lineHeight = (int)(grid->screenHeight / vec->perpWallDist);
	c->drawStart = -(c->lineHeight) / 2 + grid->screenHeight / 2;
	if(c->drawStart < 0)
		c->drawStart = 0;
	c->drawEnd = c->lineHeight / 2 + grid->screenHeight / 2;
	if(c->drawEnd >= grid->screenHeight)
		c->drawEnd = grid->screenHeight - 1;
}