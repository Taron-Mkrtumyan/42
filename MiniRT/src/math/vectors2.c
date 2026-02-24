/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:44:02 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:47:12 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	vector_normalize(t_vector *v)
{
	double		len;

	len = vec_len(v);
	if (len < VEC_EPSILON)
		return ;
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

t_vector	vector_add(const t_vector *v1, const t_vector *v2)
{
	t_vector	vec;

	vec.x = v1->x + v2->x;
	vec.y = v1->y + v2->y;
	vec.z = v1->z + v2->z;
	return (vec);
}

t_vector	vector_sub(const t_vector *v1, const t_vector *v2)
{
	t_vector	vec;

	vec.x = v1->x - v2->x;
	vec.y = v1->y - v2->y;
	vec.z = v1->z - v2->z;
	return (vec);
}

t_vector	vector_multi(const t_vector *v, double f)
{
	t_vector	vec;

	vec.x = v->x * f;
	vec.y = v->y * f;
	vec.z = v->z * f;
	return (vec);
}
