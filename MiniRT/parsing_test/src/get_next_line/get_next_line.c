#include "get_next_line.h"

char	*ft_join(char *line, char *buffer)
{
	char	*res;

	res = ft_strjoin(line, buffer);
	free(line);
	return (res);
}

char	*ft_read_file(int fd, char *line)
{
	char	*buffer;
	int	bytes_read;

	if (!line)
		line = ft_calloc(1, 1);
	bytes_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		line = ft_join(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (line);
}

char	*ft_get_line(char *line)
{
	int	i;
	char	*res;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	if (line[i] && line[i] == '\n')
		res[i++] = '\n';
	return (res);
}

char	*ft_get_next(char *line)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(line) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (line[i])
		res[j++] = line[i++];
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_next(buffer);
	return (line);
}
