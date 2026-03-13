/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:48:35 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/12 18:01:18 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	get_ratio(int width, int height)
{
	if (height == 0)
		return (1.0);
	return ((double)width / (double)height);
}

bool	init_viewport(t_minirt *rt)
{
	double	fov_rad;
	double	aspect;
	t_vec	world_up;

	rt->viewport = ft_calloc(sizeof(t_viewport), 1);
	if (!rt->viewport)
		return (false);
	fov_rad = (rt->camera->fov * M_PI) / 180.0;
	aspect = get_ratio(rt->window->width, rt->window->height);
	rt->viewport->height = 2 * tan(fov_rad / 2);
	rt->viewport->width = rt->viewport->height * aspect;
	rt->viewport->normal = normalize(rt->camera->orientation);
	if (fabs(rt->viewport->normal.y) > 0.999)
		world_up = (t_vec){0, 0, 1};
	else
		world_up = (t_vec){0, 1, 0};
	rt->viewport->right = normalize(vec_cross(world_up, rt->viewport->normal));
	rt->viewport->up = normalize(vec_cross(rt->viewport->normal, \
rt->viewport->right));
	return (true);
}
