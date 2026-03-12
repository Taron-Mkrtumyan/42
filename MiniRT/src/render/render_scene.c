/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:12 by gkankia           #+#    #+#             */
/*   Updated: 2026/03/12 18:02:15 by gkankia          ###   ########.fr       */
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

	center = vec_add(rt->camera->position, vec_multi(rt->camera->orientation, 0.5));
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

bool	render_scene(t_minirt *rt)
{
	t_point		p;
	t_ray		ray;
	t_vec		top_left;
	t_rgb		color;
	t_obj_hit	hit;

	top_left = get_viewport_top_left(rt);
	p.y = 0;
	while (p.y < rt->window->height)
	{
		p.x = 0;
		while (p.x < rt->window->width)
		{
			ray = get_ray(rt, p.x, p.y, top_left);
			hit = get_obj_hit(ray, rt->objects);
			color = get_pixel_color(rt, hit, ray.direction);
			put_pixel(rt->window, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	return (true);
}
