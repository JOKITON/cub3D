/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/31 12:22:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **ar)
{
	t_in		*in;
	t_map		*map;

	in = malloc(sizeof(t_in));
	ft_memset(in, 0, sizeof(t_in));
	in->map = ft_valid(map, ac, ar);
	in_structs(in);
	init_image(in);
	if (!in->img || (mlx_image_to_window(in->mlx_t, in->img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	get_hooks(in);
	printf("Route to the XPM file -> {%s}\n", trim_dir(in->map->no));
	mlx_loop(in->mlx_t);
	free_program(in);
	return (0);
}
