/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:54:18 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/08 19:12:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	change_floor_color(t_in *in)
{
	if (in->grid->vec->c->floor_color == 0x6289FFD9)
		in->grid->vec->c->floor_color = 0xAB89C8D9;
	else
		in->grid->vec->c->floor_color = 0x6289FFD9;
}

void	change_ceiling_color(t_in *in)
{
	if (in->grid->vec->c->ceiling_color == 0x0FA8A495)
		in->grid->vec->c->ceiling_color = 0xAB8900D9;
	else
		in->grid->vec->c->ceiling_color = 0x0FA8A495;
}
