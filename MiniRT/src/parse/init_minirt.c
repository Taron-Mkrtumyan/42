/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:12 by gkankia           #+#    #+#             */
/*   Updated: 2026/01/19 18:56:00 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	put_pixel(t_window *win, int x, int y, t_rgb color)
{
	char	*pixel;
	int		i;

	if (x < 0 || x >= win->width || y < 0 || y >= win->height)
		return ;
	pixel = win->addr + y * win->line_len + x * (win->bpp / 8);
	i = 0;
	pixel[i++] = (char)(color.b & 0xFF);
	pixel[i++] = (char)(color.g & 0xFF);
	pixel[i++] = (char)(color.r & 0xFF);
	if (win->bpp == 32)
		pixel[i] = 0;
}

t_vec	get_viewport_top_left(t_minirt *rt)
{
	t_vec	center;
	t_vec	horizontal;
	t_vec	vertical;

	center = vec_add(rt->camera->position, rt->viewport->normal);
	horizontal = vec_multi(rt->viewport->right, rt->viewport->width);
	vertical = vec_multi(rt->viewport->up, rt->viewport->height);
	return (vec_sub(vec_add(center, vec_multi(vertical, \
0.5)), vec_multi(horizontal, 0.5)));
}

t_ray	get_ray(t_minirt *rt, int x, int y, t_vec top_left)
{
	t_ray	ray;
	t_vec	pixel;
	double	u;
	double	v;

	u = (double)x / (rt->window->width - 1);
	v = (double)y / (rt->window->height - 1);
	pixel = vec_sub(vec_add(top_left, vec_multi(rt->viewport->right, \
rt->viewport->width * u)), vec_multi(rt->viewport->up, \
rt->viewport->height * v));
	ray.origin = rt->camera->position;
	ray.direction = normalize(vec_sub(pixel, ray.origin));
	return (ray);
}

bool	init_scene(t_minirt *rt)
{
	int		x;
	int		y;
	t_ray	ray;
	t_vec	top_left;
	t_rgb	color;

	top_left = get_viewport_top_left(rt);
	x = 0;
	y = 0;
	(void)ray;
	while (y < rt->window->height)
	{
		while (x < rt->window->width)
		{
			ray = get_ray(rt, x, y, top_left);
			color = (t_rgb){255, 0, 0};
			put_pixel(rt->window, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}

bool	init_minirt(t_minirt *minirt, char *filename)
{
	(void) filename;
	init_window(minirt->window);
	return (true);
}
