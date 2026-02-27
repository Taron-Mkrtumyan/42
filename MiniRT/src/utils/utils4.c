/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:34:36 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/05 19:34:59 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_error(char *msg, char **params)
{
	if (msg)
		error_msg(msg);
	if (params)
		free_arr(params);
	return (false);
}

bool	parse_error_ptr(char *msg, void *ptr, char **params)
{
	error_msg(msg);
	if (ptr)
		free(ptr);
	if (params)
		free_arr(params);
	return (false);
}

bool	error_msg(char *msg)
{
	ft_putstr_fd("\033[1;31mError\n\033[0m", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (false);
}

bool	parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params)
{
	t_obj	*obj;
	char	**params;

	obj = ft_calloc(sizeof(t_obj), 1);
	if (!obj)
		return (error_msg("Memory allocation failed"), false);
	obj->shape = type;
	obj->next = NULL;
	params = ft_split(line, ' ');
	if (!params)
		return (free(obj), error_msg("Memory allocation failed"), false);
	if (ft_arrlen(params) < nb_params)
		return (free(obj), parse_error("Invalid shape parameters", params));
	if (type == PLANE && !parse_plane(params, obj))
		return (free(obj), parse_error("Invalid plane parameters", params));
	if (type == SPHERE && !parse_sphere(params, obj))
		return (free(obj), parse_error("Invalid sphere parameters", params));
	if (type == CYLINDER && !parse_cylinder(params, obj))
		return (free(obj), parse_error("Invalid cylinder parameters", params));
	push_object(obj, &rt->objects);
	free_arr(params);
	return (true);
}
