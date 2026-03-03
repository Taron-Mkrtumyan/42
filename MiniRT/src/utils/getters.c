/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:02:01 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/03 21:10:23 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_shininess(const t_obj *obj)
{
	if (!obj || !obj->data)
		return (0.0);
	if (obj->shape == SPHERE)
		return (((t_sphere *)obj->data)->shininess);
	if (obj->shape == CYLINDER)
		return (((t_cylinder *)obj->data)->shininess);
	if (obj->shape == PLANE)
		return (((t_plane *)obj->data)->shininess);
	return (0.0);
}

t_rgbd	get_color(const t_obj *obj)
{
	if (!obj || !obj->data)
		return ((t_rgbd){0, 0, 0});
	if (obj->shape == SPHERE)
		return (((t_sphere *)obj->data)->color);
	if (obj->shape == CYLINDER)
		return (((t_cylinder *)obj->data)->color);
	if (obj->shape == PLANE)
		return (((t_plane *)obj->data)->color);
	return ((t_rgbd){0, 0, 0});
}
