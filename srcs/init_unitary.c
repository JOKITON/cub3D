/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_unitary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:07:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/05 10:12:18 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include "../includes/structs.h"

void	init_unitary(t_grid	*grid)
{
	grid->u_mapHeight = (double)grid->mapHeight;
	grid->u_mapWidth = (double)grid->mapWidth;
	grid->u_screenHeight = (double)grid->screenHeight;
	grid->u_screenWidth = (double)grid->screenWidth;

	grid->u_posX = (double)grid->posX;
	grid->u_posY = (double)grid->posY;
	grid->u_dirX = (double)grid->dirX;
	grid->u_dirY = (double)grid->dirY;
	grid->u_planeX = (double)grid->planeX;
	grid->u_planeY = (double)grid->planeY;

	
}