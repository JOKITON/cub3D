/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:23:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/25 13:33:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_front(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x + 0.1)]
			!= '1')
		in->grid->pos_x += 0.1;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x - 0.1)]
			!= '1')
			in->grid->pos_x -= 0.1;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)(in->grid->pos_y + 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += 0.1;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)(in->grid->pos_y - 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= 0.1;
}

void	move_left(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)(in->grid->pos_y - 0.1)][(int)in->grid->pos_x]
			!= '1')
		in->grid->pos_y -= 0.1;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)(in->grid->pos_y + 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += 0.1;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x - 0.1)]
			!= '1')
			in->grid->pos_x -= 0.1;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x + 0.1)]
			!= '1')
			in->grid->pos_x += 0.1;
}

void	move_right(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)(in->grid->pos_y + 0.1)][(int)in->grid->pos_x]
			!= '1')
		in->grid->pos_y += 0.1;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)(in->grid->pos_y - 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= 0.1;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x + 0.1)]
			!= '1')
			in->grid->pos_x += 0.1;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x - 0.1)]
			!= '1')
			in->grid->pos_x -= 0.1;
}

void	move_back(t_in	*in)
{
	if (in->grid->dir_x > 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x - 0.1)]
			!= '1')
		in->grid->pos_x -= 0.1;
	if (in->grid->dir_x < 0.)
		if (in->map->map[(int)in->grid->pos_y][(int)(in->grid->pos_x + 0.1)]
			!= '1')
			in->grid->pos_x += 0.1;
	if (in->grid->dir_y > 0.)
		if (in->map->map[(int)(in->grid->pos_y - 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y -= 0.1;
	if (in->grid->dir_y < 0.)
		if (in->map->map[(int)(in->grid->pos_y + 0.1)][(int)in->grid->pos_x]
			!= '1')
			in->grid->pos_y += 0.1;
}
