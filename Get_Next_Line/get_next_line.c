/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:33:13 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/17 16:02:55 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*split_line(char *line)
{
	char	*res;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	res = sub(line, i + 1, ft_strlen(line) - i);
	if (!res)
		return (NULL);
	line[i + 1] = '\0';
	return (res);
}

static char	*add_buf(int fd, char *line)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	r;

	buf[0] = '\0';
	while (has_newline(buf) == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free (line);
			line = NULL;
			return (NULL);
		}
		if (r == 0)
			break ;
		buf[r] = '\0';
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free (line);
		line = NULL;
		return (NULL);
	}
	temp = add_buf(fd, line);
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	line = split_line(temp);
	return (temp);
}
