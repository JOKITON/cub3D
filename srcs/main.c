/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/22 11:33:02 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **ar)
{
	t_in		*in;
	t_map		*map;
	
	in = malloc(sizeof(t_in));
	map = malloc(sizeof(t_map));
	ft_memset(in, 0, sizeof(t_in));
	in->map = ft_valid(map, ac, ar);
	in_structs(in);
	init_image(in);
	if (!in->mlx->win || (mlx_put_image_to_window
			(in->mlx->init, in->mlx->win, in->mlx->img->img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	get_hooks(in);
	mlx_loop(in->mlx->init);
	free_program(in);
	return (0);
}
