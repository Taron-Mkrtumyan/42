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
	pixel[i++] = (char)(color.r & 0xFF);
	pixel[i++] = (char)(color.g & 0xFF);
	pixel[i++] = (char)(color.b & 0xFF);
	if (win->bpp == 32)
		pixel[i] = 0;
}

bool	init_scene(t_minirt *rt)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < rt->window->height)
	{
		while (x < rt->window->width)
		{
			put_pixel(rt->window, x, y, (t_rgb){255, 255, 255});
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
	//if (!render_scene(minirt))
	//	return (false);
	return (true);
}
