/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:40:37 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/16 10:46:39 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-mac/mlx.h"
# include "../minilibx-mac/mlx_new_window.h"
# include "../minilibx-mac/mlx_int.h"
# include "../minilibx-mac/mlx_opengl.h"
# include "structs_image.h"
# include "structs_map.h"

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WALL 1
# define SPACE 0

// INIT_FUNCTIONS
void	in_grid(t_grid	*grid);
void	in_mlx(t_mlx *mlx);
void	in_structs(t_mlx *mlx, t_map	*map);
void	init_image(t_mlx	*mlx, t_grid	*grid);

// VECTOR_FUNCTIONS
void	init_ray_dis(t_grid	*grid, double x, t_vector	*vec);
void	step_comp_calc(t_grid	*grid, t_vector	*vec);
int		get_wall(t_grid	*grid, t_vector	*vec);
void	get_height(t_grid	*grid, t_vector	*vec, t_colors	*c);
void	draw_ver_line(t_mlx	*mlx, t_grid	*grid, t_colors	*c);

// LIBFT
void	*ft_memset(void *b, int c, size_t len);
int		ft_strvld(char *str, int i);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);

// GNL
size_t	ft_strlen_get(const char *s);

// MAP_FUNCTIONS
void	ft_hei_wid(t_map *map);
void	ft_exit_print(char *str);
void	ft_wall_map(t_map *map);
void	ft_check_char(t_map *map);
void	ft_get_params(t_map *map);
void	ft_init_struct(t_map *map);
void	ft_check_params(t_map *map);
void	ft_print_params(t_map *map);
void	ft_get_params_map(t_map *map);
void	ft_get_file(t_map *map, char *file);
void	ft_first_line(char **str, int pos, int len);
void	ft_exit_free_print(char *str, t_map *map);
void	ft_valid(t_map *map, int argc, char **arg);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_put_stars(char **str, int j, int y, int len);
void	ft_check_walls(t_map *map, char **copy, int x, int y);
void	ft_wrong_char(t_map *map, char **file, int i, int j);
void	ft_set_player(t_map *map, char **file, int i, int j);

char	*get_next_line(int fd);
int		ft_strcmp(char	*s1, char *s2);
void	ft_print_map(t_map	*map, int type);

#endif