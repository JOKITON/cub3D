/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:19:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/04 15:56:46 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	vector_scalate(t_vector *vec)
{
	vec->x *= vec->x;
	vec->y *= vec->y;
	vec->z *= vec->z;
	return (vec);
}

void	vector_add(t_vector *vec)
{
	vec->x += vec->x;
	vec->y += vec->y;
	vec->z += vec->z;
	return (vec);
}

void	vector_substract(t_vector *vec)
{
	vec->x -= vec->x;
	vec->y -= vec->y;
	vec->z -= vec->z;
}

void	vector_scalate(t_vector *vec, double scalateNumber)
{
	vec->x *= scalateNumber;
	vec->y *= scalateNumber;
	vec->z *= scalateNumber;
}

double	vector_length(t_vector *vec)
{
	double	unit;

	unit = (sqrt(vec->x * vec->x) + sqrt(vec->y * vec->y)
			+ sqrt(vec->z * vec->z));
	return (unit);
}

double	vector_unitary(t_vector *vec, double length)
{
	double	inverse_length;

	inverse_length = 1 / length;
	vec->x *= inverse_length;
	vec->y *= inverse_length;
	vec->z *= inverse_length;
}
