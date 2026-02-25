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

int	parse_vector(char *str, t_vector *vect)
{
	int		i;
	int		ret;
	char	**nbrs;

	i = -1;
	ret = 0;
	nbrs = ft_split(str, ',');
	while (nbrs && nbrs[++i])
		if (!is_float(nbrs[i]))
			ret = 1;
	if (array_length(nbrs) != 3)
		ret = 1;
	else
	{
		vect->x = str_to_float(nbrs[0]);
		vect->y = str_to_float(nbrs[1]);
		vect->z = str_to_float(nbrs[2]);
	}
	free_array(nbrs);
	return (ret);
}

int	parse_color(char *str, t_rgb *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	if (!rgb || array_length(rgb) != 3)
		return (free_array(rgb), 1);
	if (!is_ulong(rgb[0]) || !is_ulong(rgb[1]) || !is_ulong(rgb[2]))
		return (free_array(rgb), 1);
	r = str_to_int_color(rgb[0]);
	g = str_to_int_color(rgb[1]);
	b = str_to_int_color(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_array(rgb), 1);
	color->r = r;
	color->g = g;
	color->b = b;
	free_array(rgb);
	return (0);
}

int	parse_float(char *str, float *num)
{
	if (!is_float(str))
		return (1);
	*num = str_to_float(str);
	return (0);
}
