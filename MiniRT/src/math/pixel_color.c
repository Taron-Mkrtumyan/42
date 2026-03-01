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

t_rgb	pixel_color(t_amb_light *amb, t_obj *obj, t_light *light)
{
	t_rgb	res;

	(void)obj;
	res = color_multi(amb->color, amb->ratio);
	while (light)
	{
		res = color_add(res, color_multi(light->color, light->brightness));
		light = light->next;
	}
	return (res);
}
