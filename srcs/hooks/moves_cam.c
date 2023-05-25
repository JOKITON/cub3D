/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:27:51 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/25 18:03:33 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_cam_right(t_in	*in)
{
	double	temp;

	temp = in->grid->dir_x;
	in->grid->dir_x = in->grid->dir_x * cos(-3.) - in->grid->dir_y * sin(-3.);
	in->grid->dir_y = temp * sin(-3.) + in->grid->dir_y * cos(-3.);
	temp = in->grid->plane_x;
	in->grid->plane_x = in->grid->plane_x
		* cos(-3) - in->grid->plane_y * sin(-3.);
	in->grid->plane_y = temp * sin(-3) + in->grid->plane_y * cos(-3);
}

void	move_cam_left(t_in	*in)
{
	double	temp;

	temp = in->grid->dir_x;
	in->grid->dir_x = (in->grid->dir_x * cos(3)) - (in->grid->dir_y * sin(3));
	in->grid->dir_y = (temp * sin(3)) + (in->grid->dir_y * cos(3));
	temp = in->grid->plane_x;
	in->grid->plane_x = (in->grid->plane_x
			* cos(3)) - (in->grid->plane_y * sin(3));
	in->grid->plane_y = (temp * sin(3)) + (in->grid->plane_y * cos(3));
}

