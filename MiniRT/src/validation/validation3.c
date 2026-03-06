/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:07 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 17:57:54 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_shininess(char *str, double *shininess)
{
	if (!parse_double(str, shininess))
		return (false);
	if (*shininess <= 0)
		return (false);
	return (true);
}

bool	parse_plane(char **params, t_obj *obj, int fl)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (parse_error_ptr("Memory allocation failed", plane, NULL, fl));
	while (params && params[++i])
	{
		if (i == 1 && !parse_vector(params[i], &plane->center))
			return (parse_error_ptr("Invalid plane center", \
plane, NULL, fl));
		if (i == 2 && !parse_vector(params[i], &plane->normal))
			return (parse_error_ptr("Invalid plane normal", \
plane, NULL, fl));
		if (i == 3 && !parse_color(params[i], &plane->color))
			return (parse_error_ptr("Invalid plane color", \
plane, NULL, fl));
		if (i == 4 && !parse_shininess(params[i], &plane->shininess))
			return (parse_error_ptr("Invalid plane shininess value", \
plane, NULL, fl));
	}
	plane->normal = normalize(plane->normal);
	obj->data = plane;
	return (true);
}

bool	parse_sphere(char **params, t_obj *obj, int fl)
{
	int			i;
	t_sphere	*sphere;

	i = 0;
	sphere = ft_calloc(sizeof(t_sphere), 1);
	if (!sphere)
		return (parse_error_ptr("Sphere memory allocation failed", \
sphere, NULL, fl));
	while (params && params[++i])
	{
		if (i == 1 && !parse_vector(params[i], &sphere->center))
			return (parse_error_ptr("Invalid sphere center", \
sphere, NULL, fl));
		if (i == 2 && !parse_double(params[i], &sphere->diameter))
			return (parse_error_ptr("Invalid sphere diameter", \
sphere, NULL, fl));
		if (i == 3 && !parse_color(params[i], &sphere->color))
			return (parse_error_ptr("Invalid sphere color", \
sphere, NULL, fl));
		if (i == 4 && !parse_shininess(params[i], &sphere->shininess))
			return (parse_error_ptr("Invalid sphere shininess value", \
sphere, NULL, fl));
	}
	sphere->radius = sphere->diameter / 2.0;
	obj->data = sphere;
	return (true);
}

static void	init_cylinder(t_cylinder *cylinder)
{
	cylinder->normal = normalize(cylinder->normal);
	cylinder->radius = cylinder->diameter / 2.0;
}

bool	parse_cylinder(char **params, t_obj *obj, int fl)
{
	int			i;
	t_cylinder	*cylinder;

	i = 0;
	cylinder = ft_calloc(sizeof(t_cylinder), 1);
	if (!cylinder)
		return (parse_error_ptr("Memory allocation failed", \
cylinder, NULL, fl));
	while (params && params[++i])
	{
		if (i == 1 && !parse_vector(params[i], &cylinder->center))
			return (parse_error_ptr("Invalid cylinder center", \
cylinder, NULL, fl));
		if (i == 2 && !parse_vector(params[i], &cylinder->normal))
			return (parse_error_ptr("Invalid cylinder normal", \
cylinder, NULL, fl));
		if (i == 3 && !parse_double(params[i], &cylinder->diameter))
			return (parse_error_ptr("Invalid cylinder diam", \
cylinder, NULL, fl));
		if (i == 4 && !parse_double(params[i], &cylinder->height))
			return (parse_error_ptr("Invalid cylinder height", \
cylinder, NULL, fl));
		if (i == 5 && !parse_color(params[i], &cylinder->color))
			return (parse_error_ptr("Invalid cylinder color", \
cylinder, NULL, fl));
		if (i == 6 && !parse_shininess(params[i], &cylinder->shininess))
			return (parse_error_ptr("Cylinder shininess !!", \
cylinder, NULL, fl));
	}
	init_cylinder(cylinder);
	obj->data = cylinder;
	return (true);
}
