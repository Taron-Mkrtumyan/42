/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:59:21 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/01 16:00:42 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS1_H
# define VECTOR_OPERATIONS1_H

# include "structs.h"

static inline t_vec	vec_add(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

static inline t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

static inline t_vec	vec_multi(t_vec v, double f)
{
	return ((t_vec){v.x * f, v.y * f, v.z * f});
}

static inline double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

static inline double	vec_len(t_vec vec)
{
	return (hypot(hypot(vec.x, vec.y), vec.z));
}

#endif
