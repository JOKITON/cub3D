/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 11:20:06 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **ar)
{
	t_mlx		mlx;
	t_map		map;

	ft_valid(&map, ac, ar);
	in_structs(&mlx, &map);
	init_image(&mlx, mlx.grid);
	free(&mlx);
	return (0);
}
