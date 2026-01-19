/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:56 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:00 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_camera(t_minirt *rt, char *line, int i)
{
	char		**params;

	params = ft_split(line, ' ');
	if (!params)
		return (1);
	if (rt->camera)
		return (free_arr(params), 1);
	if (arr_len(params) != 4)
		return (free_arr(params), 1);
	rt->camera = ft_calloc(sizeof(t_camera), 1);
	if (!rt->camera)
		return (free_arr(params), 1);
	while (params[++i])
	{
		if (i == 1 && parse_vector(params[i], rt->camera->position))
			return (free_arr(params), 1);
		if (i == 2 && parse_vector(params[i], rt->camera->orientation))
			return (free_arr(params), 1);
		if (i == 3 && parse_float(params[i], &rt->camera->fov))
			return (free_arr(params), 1);
	}
	normalize(rt->camera->orientation);
	free_arr(params);
	return (0);
}

bool	parse_resolution(t_minirt *rt, char *line)
{
	int		i;
	char	**params;

	i = 0;
	params = ft_split(line, ' ');
	if (arr_len(params) != 3)
		return (1);
	while (params && params[++i])
	{
		if (i == 1 && parse_float(params[i], &rt->window->width))
			return (1);
		if (i == 2 && parse_float(params[i], &rt->window->height))
			return (1);
	}
	free_arr(params);
	return (0);
}

int	parse_ambient(t_minirt *rt, char *line)
{
	int		i;
	char	**params;

	i = 0;
	params = ft_split(line, ' ');
	if (rt->amb_light)
		return (1);
	if (arr_len(params) != 3)
		return (1);
	rt->amb_light = malloc(sizeof(t_amb_light));
	if (!rt->amb_light)
		return (1);
	ft_bzero(rt->amb_light, sizeof(t_amb_light));
	while (params && params[++i])
	{
		if (i == 1 && parse_float(params[i], &rt->amb_light->ratio))
			return (1);
		if (i == 2 && parse_color(params[i], rt->amb_light->color))
			return (1);
	}
	free_arr(params);
	return (0);
}

int	parse_light(t_minirt *rt, char *line)
{
	int		i;
	char	**params;
	t_light	*light;

	i = 0;
	params = ft_split(line, ' ');
	if (arr_len(params) != 4)
		return (1);
	light = create_light(rt);
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], light->position))
			return (1);
		if (i == 2 && parse_float(params[i], &light->brightness))
			return (1);
		if (i == 3 && parse_color(params[i], light->color))
			return (1);
	}
	free_arr(params);
	return (0);
}

int	parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params)
{
	t_obj	*obj;
	char	**params;

	obj = ft_calloc(sizeof(t_obj), 1);
	obj->shape = type;
	params = ft_split(line, ' ');
	if (arr_len(params) < nb_params)
		return (1);
	if (type == PLANE && parse_plane(params, obj))
		return (1);
	if (type == SPHERE && parse_sphere(params, obj))
		return (1);
	if (type == CYLINDER && parse_cylinder(params, obj))
		return (1);
	push_object(obj, rt->objects);
	free_arr(params);
	return (0);
}
