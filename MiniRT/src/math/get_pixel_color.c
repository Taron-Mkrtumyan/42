/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:52:09 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/01 15:01:11 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// I = (k_a*I_a) + (k_d * I_L * (v_N * v_L)) + (k_s * I_L * (v_R * v_V)^n_S)

t_vec	get_surface_normal(t_obj *obj, t_vec hit_point)
{
	if (!obj || !obj->data)
		return ((t_vec){0, 0, 0});
	if (obj->shape == SPHERE)
		return (normalize(vec_sub(hit_point, ((t_sphere *)obj->data)->center)));
	if (obj->shape == CYLINDER)
		return (normalize(vec_sub(hit_point, ((t_cylinder *)obj->data)->center))\
);
	if (obj->shape == PLANE)
		return (normalize(((t_plane *)obj->data)->normal));
	return ((t_vec){0, 0, 0});
}

t_rgb	get_pixel_color(t_minirt *rt, t_obj *obj, t_vec hit_point, t_vec ray)
{
	t_rgbd			res;
	t_point_vecs	vecs;
	t_lightings		lightings;
	t_light			*light;

	light = rt->lights;
	vecs.view_dir = normalize(vec_neg(ray));
	vecs.surface_normal = get_surface_normal(obj, hit_point);
	res = color_multi(rt->amb_light->color, rt->amb_light->ratio);
	lightings.diffuse = (t_rgbd){0.0, 0.0, 0.0};
	lightings.specular = (t_rgbd){0.0, 0.0, 0.0};
	while (light)
	{
		vecs.light_dir = normalize(vec_sub(light->position, hit_point));
		vecs.reflect_dir = vec_reflect(vecs.light_dir, vecs.surface_normal);
		lightings.diffuse = color_add(lightings.diffuse, color_multi(\
color_multi(color_product(light->color, get_color(obj)), light->brightness), \
fmax(0, vec_dot(vecs.light_dir, vecs.surface_normal))));
		lightings.specular = color_add(lightings.specular, color_multi(\
color_multi(light->color, light->brightness), \
pow(fmax(0, vec_dot(vecs.reflect_dir, vecs.view_dir)), get_shininess(obj))));
		light = light->next;
	}
	res = color_add(res, lightings.diffuse);
	res = color_add(res, lightings.specular);
	return (to_rgb(res));
}
