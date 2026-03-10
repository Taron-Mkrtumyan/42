/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:27:09 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/10 15:27:28 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj_hit	get_obj_hit(t_ray ray, t_obj *objs)
{
	t_obj_hit	res;
	t_obj_hit	tmp;
	t_obj		*obj;
	double		distance;

	obj = objs;
	res.obj = NULL;
	distance = INFINITY;
	while (obj)
	{
		if (does_intersect(ray, obj, &tmp))
		{
			if (tmp.t + EPSILON < distance)
			{
				distance = tmp.t;
				res = tmp;
			}
		}
		obj = obj->next;
	}
	return (res);
}
