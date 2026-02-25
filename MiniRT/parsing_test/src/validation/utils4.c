#include "minirt.h"

int	parse_error(char *msg, char **params)
{
	if (msg)
		error_msg(msg);
	if (params)
		free_array(params);
	return (1);
}

int	parse_error_ptr(char *msg, void *ptr, char **params)
{
	error_msg(msg);
	if (ptr)
		free(ptr);
	if (params)
		free_array(params);
	return (1);
}

int	error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params)
{
	t_obj	*obj;
	char	**params;

	obj = ft_calloc(sizeof(t_obj), 1);
	if (!obj)
		return (error_msg("Memory allocation failed"), 1);
	obj->shape = type;
	params = ft_split(line, ' ');
	if (!params)
		return (free(obj), error_msg("Memory allocation failed"), 1);
	if (array_length(params) < nb_params)
		return (free(obj), parse_error("Invalid shape parameters", params));
	if (type == PLANE && parse_plane(params, obj))
		return (free(obj), parse_error("Invalid plane parameters", params));
	if (type == SPHERE && parse_sphere(params, obj))
		return (free(obj), parse_error("Invalid sphere parameters", params));
	if (type == CYLINDER && parse_cylinder(params, obj))
		return (free(obj), parse_error("Invalid cylinder parameters", params));
	push_object(obj, &rt->objects);
	free_array(params);
	return (0);
}

int	parse_normal(char *str, t_vector *normal)
{
	char	**xyz;
	float	x;
	float	y;
	float	z;

	xyz = ft_split(str, ',');
	if (!xyz || array_length(xyz) != 3)
		return (free_array(xyz), 1);
	if (!is_float(xyz[0]) || !is_float(xyz[1]) || !is_float(xyz[2]))
		return (free_array(xyz), 1);
	x = str_to_float(xyz[0]);
	y = str_to_float(xyz[1]);
	z = str_to_float(xyz[2]);
	if (x < -1.0f || x > 1.0f
		|| y < -1.0f || y > 1.0f
		|| z < -1.0f || z > 1.0f)
		return (free_array(xyz), 1);
	if (x == 0.0f && y == 0.0f && z == 0.0f)
		return (free_array(xyz), 1);
	normal->x = x;
	normal->y = y;
	normal->z = z;
	normalize(normal);
	free_array(xyz);
	return (0);
}