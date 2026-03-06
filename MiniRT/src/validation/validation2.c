/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:56 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 17:40:08 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_camera_params(char **params, t_camera *cam)
{
	int	i;

	i = 0;
	while (params[++i])
	{
		if (i == 1 && !parse_vector(params[i], &cam->position))
			return (false);
		if (i == 2 && !parse_vector(params[i], &cam->orientation))
			return (false);
		if (i == 3 && !(ft_atoi(params[i]) <= 0 || ft_atoi(params[i]) > 180 || \
parse_double(params[i], &cam->fov)))
			return (printf("Invalid FOV: %d\n", ft_atoi(params[i])), false);
	}
	return (true);
}

bool	parse_camera(t_minirt *rt, char *line)
{
	char	**params;

	params = ft_split(line, ' ');
	if (!params)
		return (error_msg("Camera split failed"), 1);
	if (rt->camera)
		return (parse_error("Camera already defined", params, rt->file_line));
	if (ft_arrlen(params) != 4)
		return (parse_error("Wrong number of camera parameters", params, rt->file_line));
	rt->camera = ft_calloc(sizeof(t_camera), 1);
	if (!rt->camera)
		return (parse_error("Camera memory allocation failed", params, rt->file_line));
	if (!parse_camera_params(params, rt->camera))
		return (parse_error_ptr("Invalid camera parameters",
				NULL, params, rt->file_line));
	rt->camera->orientation = normalize(rt->camera->orientation);
	free_arr(params);
	return (true);
}

bool	parse_resolution(t_minirt *rt, char *line)
{
	int		i;
	char	**params;

	i = 0;
	params = ft_split(line, ' ');
	if (!params)
		return (error_msg("Resolution memory allocation failed"), 1);
	if (ft_arrlen(params) != 3)
		return (parse_error("Invalid resolution parameters", params, rt->file_line));
	while (params[++i])
	{
		if (i == 1 && !parse_double(params[i], &rt->window->width))
			return (parse_error("Invalid width resolution", params, rt->file_line));
		if (i == 2 && !parse_double(params[i], &rt->window->height))
			return (parse_error("Invalid height resolution", params, rt->file_line));
	}
	free_arr(params);
	return (true);
}

bool	parse_ambient(t_minirt *rt, char *line)
{
	int		i;
	char	**params;

	i = 0;
	params = ft_split(line, ' ');
	if (!params)
		return (error_msg("Ambient split failed"), 1);
	if (rt->amb_light)
		return (parse_error("Ambient light already defined", params, rt->file_line));
	if (ft_arrlen(params) != 3)
		return (parse_error("Wrong number of ambient light parameters", \
params, rt->file_line));
	rt->amb_light = ft_calloc(sizeof(t_amb_light), 1);
	if (!rt->amb_light)
		return (parse_error("Memory allocation failed", params, rt->file_line));
	while (params[++i])
	{
		if (i == 1 && !parse_double(params[i], &rt->amb_light->ratio))
			return (parse_error_ptr("Invalid ambient ratio",
					NULL, params, rt->file_line));
		if (i == 2 && !parse_color(params[i], &rt->amb_light->color))
			return (parse_error_ptr("Invalid ambient color",
					NULL, params, rt->file_line));
	}
	free_arr(params);
	return (true);
}

bool	parse_light(t_minirt *rt, char *line)
{
	int		i;
	char	**params;
	t_light	*light;

	i = 0;
	params = ft_split(line, ' ');
	if (!params)
		return (error_msg("Light split allocation failed"), 1);
	if (ft_arrlen(params) != 4)
		return (parse_error("Invalid light parameters", params, rt->file_line));
	light = create_light(rt);
	if (!light)
		return (parse_error("Light memory allocation failed", params, rt->file_line));
	while (params[++i])
	{
		if (i == 1 && !parse_vector(params[i], &light->position))
			return (parse_error_ptr("Invalid light position", NULL, params, rt->file_line));
		if (i == 2 && !parse_double(params[i], &light->brightness))
			return (parse_error_ptr("Invalid light brightness", NULL, params, rt->file_line));
		if (i == 3 && !parse_color(params[i], &light->color))
			return (parse_error_ptr("Invalid light color", NULL, params, rt->file_line));
	}
	free_arr(params);
	return (true);
}
