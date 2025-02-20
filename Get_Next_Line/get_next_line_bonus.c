/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:14:52 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/20 18:19:06 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*line[OPEN_MAX];
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free (line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	temp = add_buf(fd, line[fd]);
	if (!temp)
	{
		free (temp);
		return (NULL);
	}
	line[fd] = split_line(temp);
	return (temp);
}

/*
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	fd1;
	int	fd2;

    (void)ac;
    (void)av;
	fd1 = open("file.txt", O_RDWR);
	fd2 = open("file2.txt", O_RDWR);
	i = 0;
	while (i++ < 8)
    {
		printf("res: %s\n", get_next_line(fd1));
		printf("res: %s\n", get_next_line(fd2));
    }
	return (0);
}
//printf("\nFOPEN_MAX: %u\nOPEN_MAX: %u\n", FOPEN_MAX, OPEN_MAX);
*/