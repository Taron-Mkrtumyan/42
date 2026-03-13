/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:52:09 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 20:39:41 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// I = (k_a*I_a) + (k_d * I_L * (v_N * v_L)) + (k_s * I_L * (v_R * v_V)^n_S)

static bool	is_in_shadow(t_obj *obj, t_obj_hit obj_hit, t_vec light_dir, \
t_vec light_position)
{
	t_obj_hit		tmp;

	while (obj)
	{
		tmp.t = INFINITY;
		tmp.obj = NULL;
		if (obj != obj_hit.obj && does_intersect((t_ray)\
{obj_hit.hit_point, light_dir}, obj, &tmp) && tmp.t < vec_len(\
vec_sub(light_position, obj_hit.hit_point)))
			return (true);
		obj = obj->next;
	}
	return (false);
}

t_rgb	get_pixel_color(t_minirt *rt, t_obj_hit obj_hit, t_vec ray_dir)
{
	t_vec			light_dir;
	t_lightings		lightings;
	t_light			*light;

	if (!obj_hit.obj)
		return ((t_rgb){0, 0, 0});
	light = rt->lights;
	lightings.diffuse = (t_rgbd){0.0, 0.0, 0.0};
	lightings.specular = (t_rgbd){0.0, 0.0, 0.0};
	while (light)
	{
		light_dir = normalize(vec_sub(light->position, obj_hit.hit_point));
		if (!is_in_shadow(rt->objects, obj_hit, light_dir, light->position))
		{
			lightings.diffuse = color_add(lightings.diffuse, color_multi(\
color_multi(color_product(light->color, get_color(obj_hit.obj)), \
light->brightness), fmax(0, vec_dot(light_dir, obj_hit.normal))));
			lightings.specular = color_add(lightings.specular, \
color_multi(color_multi(light->color, light->brightness), \
pow(fmax(0.0, vec_dot(vec_reflect(light_dir, obj_hit.normal), \
normalize(vec_neg(ray_dir)))), get_shininess(obj_hit.obj))));
		}
		light = light->next;
	}
	return (to_rgb(color_add(color_product(color_multi(rt->amb_light->color, \
rt->amb_light->ratio), get_color(obj_hit.obj)), color_add(lightings.diffuse, \
lightings.specular))));
}
