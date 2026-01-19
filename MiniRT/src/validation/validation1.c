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

bool	parse_params(t_minirt *minirt, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0)
		return (parse_resolution(minirt, line));
	if (ft_strncmp(line, "A", 1) == 0)
		return (parse_ambient(minirt, line));
	if (ft_strncmp(line, "C", 1) == 0)
		return (parse_camera(minirt, line, 0));
	if (ft_strncmp(line, "L", 1) == 0)
		return (parse_light(minirt, line));
	if (ft_strncmp(line, "sp", 2) == 0)
		return (parse_shape(minirt, line, SPHERE, 4));
	if (ft_strncmp(line, "pl", 2) == 0)
		return (parse_shape(minirt, line, PLANE, 4));
	if (ft_strncmp(line, "cy", 2) == 0)
		return (parse_shape(minirt, line, CYLINDER, 6));
	return (0);
}

int	is_invalid_file(t_minirt *minirt)
{
	if (!minirt->camera)
		return (1);
	if (!minirt->lights)
		return (1);
	if (!minirt->amb_light)
		return (1);
	return (0);
}

char	*clear_line(char *line)
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

int	read_file(t_minirt *rt, int fd)
{
	int		num;
	int		ret;
	char	*line;

	num = 0;
	ret = 0;
	while (ret != 1)
	{
		num++;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = clear_line(line);
		if (parse_params(rt, line))
			ret = 1;
		free(line);
	}
	if (!ret && is_invalid_file(rt))
		ret = 1;
	close(fd);
	return (ret);
}

bool	valid_args(t_minirt *rt, char *path)
{
	int	fd;
	int	len;

	rt->window = malloc(sizeof(t_window));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	len = ft_strlen(path);
	if (len < 3 || ft_strncmp(path + len - 3, ".rt", 3) != 0)
	{
		close(fd);
		return (0);
	}
	if (read_file(rt, fd))
		return (0);
	return (1);
}
