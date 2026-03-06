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

t_rgb	get_pixel_color(t_minirt *rt, t_obj_hit obj_hit, t_vec ray_dir)
{
	t_rgbd			res;
	t_point_vecs	vecs;
	t_lightings		lightings;
	t_light			*light;

	light = rt->lights;
	vecs.view_dir = normalize(vec_neg(ray_dir));
	res = color_multi(rt->amb_light->color, rt->amb_light->ratio);
	lightings.diffuse = (t_rgbd){0.0, 0.0, 0.0};
	lightings.specular = (t_rgbd){0.0, 0.0, 0.0};
	while (light)
	{
		vecs.light_dir = normalize(vec_sub(light->position, obj_hit.hit_point));
		vecs.reflect_dir = vec_reflect(vecs.light_dir, obj_hit.normal);
		lightings.diffuse = color_add(lightings.diffuse, color_multi(\
color_multi(color_product(light->color, get_color(obj_hit.obj)), \
light->brightness), fmax(0, vec_dot(vecs.light_dir, obj_hit.normal))));
		lightings.specular = color_add(lightings.specular, color_multi(\
color_multi(light->color, light->brightness), \
pow(fmax(0, vec_dot(vecs.reflect_dir, vecs.view_dir)), \
get_shininess(obj_hit.obj))));
		light = light->next;
	}
	res = color_add(res, lightings.diffuse);
	res = color_add(res, lightings.specular);
	return (to_rgb(res));
}
