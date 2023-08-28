/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:54:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/28 16:47:41 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	change_floor_color(t_in *in)
{
	in->grid->vec->c->floor_color = 0x00A8A495;
}

void	change_ceiling_color(t_in *in)
{
	in->grid->vec->c->ceiling_color = 0x6289FF00;
}
