/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:39:31 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/03 15:07:15 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_arr(char *arr[])
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

void	free_window(t_window *win)
{
	if (!win)
		return ;
	if (win->img)
		mlx_destroy_image(win->mlx, win->img);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
		mlx_destroy_display(win->mlx);
	free(win->mlx);
	free(win);
}

void	free_objects(t_obj *obj)
{
	t_obj	*tmp;

	while (obj)
	{
		tmp = obj->next;
		if (obj->data)
			free(obj->data);
		free(obj);
		obj = tmp;
	}
}

void	free_lights(t_light *light)
{
	t_light	*tmp;

	while (light)
	{
		tmp = light->next;
		free(light);
		light = tmp;
	}
}

void	free_minirt(t_minirt *rt)
{
	if (!rt)
		return ;
	if (rt->window)
		free_window(rt->window);
	if (rt->camera)
		free(rt->camera);
	if (rt->lights)
		free_lights(rt->lights);
	if (rt->amb_light)
		free(rt->amb_light);
	if (rt->objects)
		free_objects(rt->objects);
	if (rt->viewport)
		free(rt->viewport);
	free(rt);
}
