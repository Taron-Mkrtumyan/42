/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:04:26 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 21:04:42 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static inline t_vec	get_sphere_normal(t_sphere *sphere, t_vec hit_point)
{
	return (normalize(vec_sub(hit_point, sphere->center)));
}

t_hit_surface	get_hit_surface(t_cylinder *cylinder, t_vec hit_point)
{
	t_vec	diff;
	double	m;
	double	half;

	diff = vec_sub(hit_point, cylinder->center);
	m = vec_dot(diff, cylinder->normal);
	half = cylinder->height * 0.5;
	if (m < -half || m > half)
		return (NO_HIT);
	if (m >= half - EPSILON)
		return (HIT_TOP);
	if (m <= -half + EPSILON)
		return (HIT_BOTTOM);
	return (HIT_SIDE);
}

t_vec	get_cylinder_normal(t_cylinder *cylinder, t_vec hit_point)
{
	t_vec			v;
	t_hit_surface	hit_surface;

	hit_surface = get_hit_surface(cylinder, hit_point);
	if (hit_surface == HIT_TOP)
		return (cylinder->normal);
	if (hit_surface == HIT_BOTTOM)
		return (vec_neg(cylinder->normal));
	v = vec_sub(hit_point, cylinder->center);
	return (normalize(vec_sub(v, vec_multi(cylinder->normal, \
vec_dot(v, cylinder->normal)))));
}

t_vec	get_surface_normal(t_obj *obj, t_vec hit_point)
{
	if (!obj || !obj->data)
		return ((t_vec){0, 0, 0});
	if (obj->shape == SPHERE)
		return (get_sphere_normal((t_sphere *)obj->data, hit_point));
	if (obj->shape == CYLINDER)
		return (get_cylinder_normal((t_cylinder *)obj->data, hit_point));
	if (obj->shape == PLANE)
		return (normalize(((t_plane *)obj->data)->normal));
	return ((t_vec){0, 0, 0});
}
