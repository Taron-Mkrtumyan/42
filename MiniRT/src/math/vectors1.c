/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:33:04 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/24 19:34:17 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_len(const t_vector *vec)
{
	return (hypot(hypot(vec->x, vec->y), vec->z));
}

double	vec_dot(const t_vector *v1, const t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

// hypot (x, y) = sqrt(x*x + y*y)
// vec_len = sqrt(x^2 + y^2 + z^2)
