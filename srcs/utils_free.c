/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:51:50 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/28 16:49:27 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_doublefree(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	free_program(t_in	*in)
{
	ft_doublefree(in->map->star);
	ft_doublefree(in->map->map);
	ft_doublefree(in->map->file);
	free(in->map);
	free(in->mlx->img);
	free(in->textures);
	free(in->grid->vec->c);
	free(in->grid->vec);
	free(in->grid);
	free(in->time);
	free(in);
	mlx_destroy_window(in->mlx->init, in->mlx->win);
	exit (EXIT_SUCCESS);
}
