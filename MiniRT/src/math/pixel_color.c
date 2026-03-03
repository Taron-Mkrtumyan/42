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

t_rgb	pixel_color(t_ray *ray, t_amb_light *amb, t_obj *obj, t_light *light)
{
	t_rgb	res;
	t_rgb	ambient;
	t_rgb	diffuse;
	t_rgb	specular;

	(void)obj;
	(void)ray;
	(void)light;
	ambient = color_multi(amb->color, amb->ratio);
	diffuse = (t_rgb){0, 0, 0};
	specular = (t_rgb){0, 0, 0};
// 	while (light)
// 	{
// 		//diffuse = color_add(diffuse, color_multi(color_multi(light->color, \
// light->brightness), vec_dot(light->position, obj->normal)));
// 		//specular = color_add(specular, color_multi(color_multi(light->color, \
// light->brightness), pow(vec_dot(light->position, vec_norm(ray, obj)), \
// obj->shininess)));
// 		light = light->next;
// 	}
	res = color_add(ambient, diffuse);
	res = color_add(res, specular);
	return (res);
}
