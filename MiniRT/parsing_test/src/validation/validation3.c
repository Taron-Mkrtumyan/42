#include "minirt.h"

int	parse_plane(char **params, t_obj *obj)
{
	int		i;
	t_plane	*plane;

	i = 0;
	plane = ft_calloc(sizeof(t_plane), 1);
	if (!plane)
		return (parse_error_ptr("Memory allocation failed", plane, NULL));
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], &plane->center))
			return (parse_error_ptr("Invalid plane center", plane, NULL));
		if (i == 2 && parse_normal(params[i], &plane->normal))
			return (parse_error_ptr("Invalid plane normal", plane, NULL));
		if (i == 3 && parse_color(params[i], &plane->color))
			return (parse_error_ptr("Invalid plane color", plane, NULL));
	}
	normalize(&plane->normal);
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
		return (parse_error_ptr("Memory allocation failed", sphere, NULL));
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], &sphere->center))
			return (parse_error_ptr("Invalid sphere center", sphere, NULL));
		if (i == 2 && parse_float(params[i], &sphere->diameter))
			return (parse_error_ptr("Invalid sphere diameter", sphere, NULL));
		if (i == 3 && parse_color(params[i], &sphere->color))
			return (parse_error_ptr("Invalid sphere color", sphere, NULL));
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
		return (parse_error_ptr("Memory allocation failed", cylinder, NULL));
	while (params && params[++i])
	{
		if (i == 1 && parse_vector(params[i], &cylinder->center))
			return (parse_error_ptr("Invalid cylinder center", cylinder, NULL));
		if (i == 2 && parse_normal(params[i], &cylinder->normal))
			return (parse_error_ptr("Invalid cylinder normal", cylinder, NULL));
		if (i == 3 && parse_float(params[i], &cylinder->diameter))
			return (parse_error_ptr("Invalid cylinder diameter", cylinder, NULL));
		if (i == 4 && parse_float(params[i], &cylinder->height))
			return (parse_error_ptr("Invalid cylinder height", cylinder, NULL));
		if (i == 5 && parse_color(params[i], &cylinder->color))
			return (parse_error_ptr("Invalid cylinder color", cylinder, NULL));
	}
	normalize(&cylinder->normal);
	cylinder->radius = cylinder->diameter / 2.0f;
	obj->data = cylinder;
	return (0);
}
