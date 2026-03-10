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

static bool	cylinder_solve(double a, double b, double c, t_obj_hit *hit)
{
	double	discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	if (t1 < EPSILON)
	{
		if (t2 < EPSILON)
			return (false);
		hit->t = t2;
	}
	else
		hit->t = t1;
	return (true);
}

static bool	does_intersect_cylinder(t_ray ray, t_cylinder *cyl, t_obj_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	tmp;
	t_vec	oc;

	tmp = vec_dot(ray.direction, cyl->normal);
	a = vec_dot(ray.direction, ray.direction) - tmp * tmp;
	if (fabs(a) < EPSILON)
		return (false);
	oc = vec_sub(ray.origin, cyl->center);
	b = -2 * tmp;
	tmp = vec_dot(oc, cyl->normal);
	b = b * tmp + 2 * vec_dot(ray.direction, oc);
	c = vec_dot(oc, oc) - cyl->radius * cyl->radius - tmp * tmp;
	if (!cylinder_solve(a, b, c, hit))
		return (false);
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
	if (get_hit_surface(cyl, hit->hit_point) == NO_HIT)
		return (false);
	return (true);
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
		hit->normal = get_surface_normal(hit->obj, hit->hit_point);
	return (hit->obj != NULL);
}
