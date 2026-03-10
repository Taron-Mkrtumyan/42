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
}
