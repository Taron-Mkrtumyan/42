/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:29:45 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 20:33:43 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	does_intersect_sphere(t_ray ray, t_sphere *sphere, t_obj_hit *hit)
{
	t_vec			oc;
	t_quadratic_eq	qe;
	double			t;

	oc = vec_sub(ray.origin, sphere->center);
	qe.b = 2 * vec_dot(ray.direction, oc);
	qe.c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	qe.discriminant = qe.b * qe.b - 4 * qe.c;
	if (qe.discriminant < EPSILON)
		return (false);
	t = (-qe.b - sqrt(qe.discriminant)) / 2;
	if (t < EPSILON)
	{
		t = (-qe.b + sqrt(qe.discriminant)) / 2;
		if (t < EPSILON)
			return (false);
	}
	hit->t = t;
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, t));
	return (true);
}

static bool	does_intersect_plane(t_ray ray, t_plane *plane, t_obj_hit *hit)
{
	double	d;
	double	t;

	d = vec_dot(ray.direction, plane->normal);
	if (fabs(d) < EPSILON)
		return (false);
	t = -vec_dot(vec_sub(ray.origin, plane->center), plane->normal) / d;
	if (t < EPSILON)
		return (false);
	hit->t = t;
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
	return (true);
}

bool	does_intersect(t_ray ray, t_obj *obj, t_obj_hit *hit)
{
	if (!obj || !hit)
		return (false);
	hit->obj = NULL;
	if (obj->shape == PLANE)
	{
		if (does_intersect_plane(ray, (t_plane *)obj->data, hit))
			hit->obj = obj;
	}
	if (obj->shape == SPHERE)
	{
		if (does_intersect_sphere(ray, (t_sphere *)obj->data, hit))
			hit->obj = obj;
	}
	if (obj->shape == CYLINDER)
	{
		if (does_intersect_cylinder(ray, (t_cylinder *)obj->data, hit))
			hit->obj = obj;
	}
	if (hit->obj)
		hit->normal = get_surface_normal(hit->obj, hit->hit_point, \
ray.direction);
	return (hit->obj != NULL);
}
