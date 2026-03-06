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

static bool	does_intersect_cylinder(t_ray ray, t_cylinder *cyl, t_obj_hit *hit)
{
	(void)ray;
	(void)cyl;
	(void)hit;
	return (false);
}

static bool	does_intersect_sphere(t_ray ray, t_sphere *sphere, t_obj_hit *hit)
{
	t_vec	oc;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = vec_sub(ray.origin, sphere->center);
	b = 2 * vec_dot(ray.direction, oc);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = b * b - 4 * c;
	if (discriminant < 0)
		return (false);
	t = (-b - sqrt(discriminant)) / 2;
	if (t < EPSILON)
	{
		t = (-b + sqrt(discriminant)) / 2;
		if (t < EPSILON)
			return (false);
	}
	hit->t = t;
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, t));
	return (true);
}

static bool	does_intersect_plane(t_ray ray, t_plane *plane, t_obj_hit *hit)
{
	t_vec	x;
	double	d;
	double	t;

	d = vec_dot(ray.direction, plane->normal);
	if (fabs(d) < EPSILON)
		return (false);
	x = vec_sub(ray.origin, plane->center);
	t = -vec_dot(x, plane->normal) / d;
	if (t < 0)
		return (false);
	hit->t = t;
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
	hit->normal = plane->normal;
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
		hit->normal = get_surface_normal(hit->obj, hit->hit_point);
	return (hit->obj != NULL);
}

t_obj_hit	get_obj_hit(t_ray ray, t_obj *objs)
{
	t_obj_hit	res;
	t_obj		*obj;
	double		distance;

	obj = objs;
	res.obj = NULL;
	distance = 0;
	while (obj)
	{
		if (does_intersect(ray, obj, &res))
		{
			if (distance < vec_len(vec_sub(res.hit_point, ray.origin)))
			{
				distance = vec_len(vec_sub(res.hit_point, ray.origin));
				res.obj = obj;
			}
		}
		obj = obj->next;
	}
	return (res);
}
