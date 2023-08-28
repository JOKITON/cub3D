/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:51:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/08/28 12:42:47 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	getrgb(int r, int g, int b)
{
	return ((r * 255) + (g * 255) + (b * 255));
}

int	get_colors(char	*str)
{
	char	**numbers;

	str = ft_substr(str, 2, ft_strlen(str) - 1);
	numbers = ft_split(str, ',');
	return (getrgb(ft_atoi(numbers[0]), ft_atoi(numbers[1]), ft_atoi(numbers[2])));
}

int	main(int ac, char **ar)
{
	t_in		*in;
	t_map		*map;

	in = malloc(sizeof(t_in));
	map = malloc(sizeof(t_map));
	ft_memset(in, 0, sizeof(t_in));
	in->map = ft_valid(map, ac, ar);
	in_structs(in);
	in->grid->vec->c->ceiling_color = get_colors(in->map->c);
	in->grid->vec->c->floor_color = get_colors(in->map->f);
	init_image(in);
	if (!in->mlx->win || (mlx_put_image_to_window
			(in->mlx->init, in->mlx->win, in->mlx->img->img, 0, 0) < 0))
		exit(EXIT_FAILURE);
	get_hooks(in);
	mlx_loop(in->mlx->init);
	free_program(in);
	return (0);
}
