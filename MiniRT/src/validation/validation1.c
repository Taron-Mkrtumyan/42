/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:19 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:33:39 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_params(t_minirt *rt, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (parse_resolution(rt, line));
	if (ft_strncmp(line, "A ", 2) == 0)
		return (parse_ambient(rt, line));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_camera(rt, line));
	if (ft_strncmp(line, "L ", 2) == 0)
		return (parse_light(rt, line));
	if (ft_strncmp(line, "sp ", 3) == 0)
		return (parse_shape(rt, line, SPHERE, 4));
	if (ft_strncmp(line, "pl ", 3) == 0)
		return (parse_shape(rt, line, PLANE, 4));
	if (ft_strncmp(line, "cy ", 3) == 0)
		return (parse_shape(rt, line, CYLINDER, 6));
	return (error_msg("Invalid parameter"), false);
}

bool	is_valid_file(t_minirt *rt)
{
	if (!rt->camera)
		return (error_msg("No camera defined"), false);
	if (!rt->light)
		return (error_msg("No light defined"), false);
	if (!rt->amb_light)
		return (error_msg("No ambient light defined"), false);
	return (true);
}

static char	*clear_line(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = line;
	while (tmp && tmp[++i])
		if (tmp[i] == '\t' || tmp[i] == '\n')
			tmp[i] = ' ';
	line = ft_strtrim(tmp, " ");
	free(tmp);
	return (line);
}

static bool	read_file(t_minirt *rt, int fd)
{
	int		num;
	bool	ret;
	char	*line;

	num = 0;
	ret = true;
	while (ret != false)
	{
		num++;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = clear_line(line);
		if (!parse_params(rt, line))
			ret = false;
		free(line);
	}

	if (ret && !is_valid_file(rt))
	{
		error_msg("Invalid file");
		ret = false;
	}
	close(fd);
	return (ret);
}

bool	valid_args(t_minirt *rt, char *path, int ac)
{
	int	fd;
	int	len;

	if (ac != 2)
		return (error_msg("Wrong number of arguments"), false);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (error_msg("Failed to open file"), false);
	len = ft_strlen(path);
	if (len <= 3 || ft_strncmp(path + len - 3, ".rt", 3) != 0)
	{
		close(fd);
		return (error_msg("Invalid file extension"), false);
	}
	if (!read_file(rt, fd))
		return (false);
	return (true);
}
