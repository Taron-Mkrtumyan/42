/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:40 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:42 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	str_to_int_color(char *str)
{
	int	c;

	c = ft_atoi(str);
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (c);
}

bool	parse_vector(char *str, t_vector *vec)
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

bool	parse_color(char *str, t_rgb *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!rgb || ft_arrlen(rgb) != 3)
		return (free_arr(rgb), false);
	if (!is_ulong(rgb[0]) || !is_ulong(rgb[1]) || !is_ulong(rgb[2]))
		return (free_arr(rgb), false);
	r = str_to_int_color(rgb[0]);
	g = str_to_int_color(rgb[1]);
	b = str_to_int_color(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_arr(rgb), false);
	color->r = r;
	color->g = g;
	color->b = b;
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
