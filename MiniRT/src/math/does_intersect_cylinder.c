/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_intersect_cylinder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:06:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/10 19:07:56 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	cylinder_solve(double a, double b, double c, t_obj_hit *hit)
{
	double	discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < EPSILON)
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

static bool	intersect_cap(t_ray ray, t_vec center, t_vec norm, t_cylinder *cyl)
{
	double	denom;
	double	tt;
	t_vec	p;

	denom = vec_dot(ray.direction, norm);
	if (fabs(denom) < EPSILON)
		return (false);
	tt = vec_dot(vec_sub(center, ray.origin), norm) / denom;
	if (tt < EPSILON)
		return (false);
	p = vec_add(ray.origin, vec_multi(ray.direction, tt));
	if (vec_len(vec_sub(p, center)) > cyl->radius)
		return (false);
	cyl->cap_t = tt;
	return (true);
}
/*
bool	does_intersect_cylinder(t_ray ray, t_cylinder *cyl, t_obj_hit *hit)
{
	t_quadratic_eq	qe;
	double			tmp;
	t_vec			oc;

	tmp = vec_dot(ray.direction, cyl->normal);
	qe.a = vec_dot(ray.direction, ray.direction) - tmp * tmp;
	if (fabs(qe.a) < EPSILON)
		return (false);
	oc = vec_sub(ray.origin, cyl->center);
	qe.b = -2 * tmp;
	tmp = vec_dot(oc, cyl->normal);
	qe.b = qe.b * tmp + 2 * vec_dot(ray.direction, oc);
	qe.c = vec_dot(oc, oc) - cyl->radius * cyl->radius - tmp * tmp;
	if (!cylinder_solve(qe.a, qe.b, qe.c, hit))
		return (false);
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
	if (get_hit_surface(cyl, hit->hit_point) == NO_HIT)
		return (false);
	return (true);
}*/

bool	does_intersect_cylinder(t_ray ray, t_cylinder *cyl, t_obj_hit *hit)
{
	double	a;
	double	tmp;
	t_vec	oc;

	hit->t = INFINITY;
	tmp = vec_dot(ray.direction, cyl->normal);
	oc = vec_sub(ray.origin, cyl->center);
	a = vec_dot(ray.direction, ray.direction) - tmp * tmp;
	if (fabs(a) > EPSILON && cylinder_solve(a, 2 * (vec_dot\
(ray.direction, oc) - tmp * vec_dot(oc, cyl->normal)), vec_dot(oc, oc) - \
pow(vec_dot(oc, cyl->normal), 2) - cyl->radius * cyl->radius, hit))
	{
		hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
		if (get_hit_surface(cyl, hit->hit_point) == NO_HIT)
			hit->t = INFINITY;
	}
	if (intersect_cap(ray, cyl->top_center, cyl->normal, cyl))
		if (cyl->cap_t < hit->t)
			hit->t = cyl->cap_t;
	if (intersect_cap(ray, cyl->bottom_center, vec_neg(cyl->normal), cyl))
		if (cyl->cap_t < hit->t)
			hit->t = cyl->cap_t;
	if (hit->t == INFINITY)
		return (false);
	hit->hit_point = vec_add(ray.origin, vec_multi(ray.direction, hit->t));
	return (true);
}
