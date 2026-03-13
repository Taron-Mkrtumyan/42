/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:59:53 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 19:03:25 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params)
{
	t_obj	*obj;
	char	**params;

	obj = ft_calloc(sizeof(t_obj), 1);
	if (!obj)
		return (error_msg("Shape memory allocation failed"), false);
	obj->shape = type;
	obj->next = NULL;
	params = ft_split(line, ' ');
	if (!params)
		return (free(obj), error_msg("Shape split failed"), false);
	if (ft_arrlen(params) < nb_params)
		return (free(obj), parse_error("Few shape parameters: ", \
params, rt->file_line), printf("%s\n", line), false);
	if (type == PLANE && !parse_plane(params, obj, rt->file_line))
		return (free(obj), free_arr(params), false);
	if (type == SPHERE && !parse_sphere(params, obj, rt->file_line))
		return (free(obj), free_arr(params), false);
	if (type == CYLINDER && !parse_cylinder(params, obj, rt->file_line))
		return (free(obj), free_arr(params), false);
	push_object(obj, &rt->objects);
	free_arr(params);
	return (true);
}

bool	parse_vector(char *str, t_vec *vec)
{
	int		i;
	bool	ret;
	char	**nbrs;

	i = -1;
	ret = true;
	nbrs = ft_split(str, ',');
	while (nbrs && nbrs[++i])
		if (!is_double(nbrs[i]))
			ret = false;
	if (ft_arrlen(nbrs) != 3)
		ret = false;
	else
	{
		vec->x = ft_strtod(nbrs[0]);
		vec->y = ft_strtod(nbrs[1]);
		vec->z = ft_strtod(nbrs[2]);
	}
	free_arr(nbrs);
	return (ret);
}

bool	parse_color(char *str, t_rgbd *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!rgb || ft_arrlen(rgb) != 3)
		return (free_arr(rgb), false);
	if (!is_uchar(rgb[0]) || !is_uchar(rgb[1]) || !is_uchar(rgb[2]))
		return (free_arr(rgb), false);
	r = str_to_int_color(rgb[0]);
	g = str_to_int_color(rgb[1]);
	b = str_to_int_color(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_arr(rgb), false);
	color->r = (double)r / 255;
	color->g = (double)g / 255;
	color->b = (double)b / 255;
	free_arr(rgb);
	return (true);
}

bool	parse_double(char *str, double *num)
{
	if (!is_double(str))
		return (false);
	*num = ft_strtod(str);
	return (true);
}
