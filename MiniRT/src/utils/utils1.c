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

int	parse_vector(char *str, t_vector *vec)
{
	int		i;
	int		ret;
	char	**nbrs;

	i = -1;
	ret = 0;
	nbrs = ft_split(str, ',');
	while (nbrs && nbrs[++i])
		if (!is_double(nbrs[i]))
			ret = 1;
	if (arr_len(nbrs) != 3)
		ret = 1;
	else
	{
		vec->x = str_to_double(nbrs[0]);
		vec->y = str_to_double(nbrs[1]);
		vec->z = str_to_double(nbrs[2]);
	}
	free_arr(nbrs);
	return (ret);
}

int	parse_colors(char *str, t_rgb *color1, t_rgb *color2)
{
	int		i;
	int		ret;
	char	**colors;

	i = -1;
	ret = 0;
	colors = ft_split(str, ';');
	if (arr_len(colors) < 1)
		ret = 1;
	while (colors && colors[++i])
	{
		if (i == 0)
			ret = parse_color(colors[0], color1);
		if (i == 1)
			ret = parse_color(colors[1], color2);
	}
	free_arr(colors);
	return (ret);
}

int	parse_color(char *str, t_rgb *color)
{
	int		i;
	int		ret;
	char	**rgb;

	i = -1;
	ret = 0;
	rgb = ft_split(str, ',');
	while (rgb && rgb[++i])
		if (!is_ulong(rgb[i]))
			ret = 1;
	if (arr_len(rgb) != 3)
		ret = 1;
	else
	{
		color->r = str_to_int_color(rgb[0]);
		color->g = str_to_int_color(rgb[1]);
		color->b = str_to_int_color(rgb[2]);
	}
	free_arr(rgb);
	return (ret);
}

int	parse_double(char *str, double *num)
{
	if (!is_double(str))
		return (1);
	*num = str_to_double(str);
	return (0);
}
