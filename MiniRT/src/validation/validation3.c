/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:07 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:09 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_plane(char **params, t_obj *obj)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (1);
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], plane->center))
			return (1);
		if (i == 2 && parse_vector(params[i], plane->normal))
			return (1);
		if (i == 3 && parse_color(params[i], plane->color))
			return (1);
	}
	normalize(plane->normal);
	obj->data = plane;
	return (0);
}

int	parse_sphere(char **params, t_obj *obj)
{
	int			i;
	t_sphere	*sphere;

	i = 0;
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (1);
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], sphere->center))
			return (1);
		if (i == 2 && parse_float(params[i], &sphere->diameter))
			return (1);
		if (i == 3 && parse_color(params[i], sphere->color))
			return (1);
	}
	sphere->radius = sphere->diameter / 2.0f;
	obj->data = sphere;
	return (0);
}

int	parse_cylinder(char **params, t_obj *obj)
{
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (1);
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], cylinder->center))
			return (1);
		if (i == 2 && parse_vector(params[i], cylinder->normal))
			return (1);
		if (i == 3 && parse_float(params[i], &cylinder->diameter))
			return (1);
		if (i == 4 && parse_float(params[i], &cylinder->height))
			return (1);
		if (i == 5 && parse_color(params[i], cylinder->color))
			return (1);
	}
	normalize(cylinder->normal);
	cylinder->radius = cylinder->diameter / 2.0f;
	obj->data = cylinder;
	return (0);
}
