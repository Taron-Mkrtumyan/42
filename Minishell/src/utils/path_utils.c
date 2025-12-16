/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:18 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:42:35 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_dirs(char *path)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (path[i])
	{
		if (path[i] == ':')
			count++;
		i++;
	}
	return (count);
}

char	*copy_part(char *src, int start, int end)
{
	char	*part;
	int		len;
	int		i;

	len = end - start;
	part = malloc(len + 1);
	if (!part)
		return (NULL);
	i = 0;
	while (start < end)
		part[i++] = src[start++];
	part[i] = '\0';
	return (part);
}

char	**split_dirs(char *path)
{
	char	**dirs;
	int		i;
	int		start;
	int		idx;

	dirs = malloc(sizeof(char *) * (count_dirs(path) + 1));
	if (!dirs)
		return (NULL);
	i = 0;
	idx = 0;
	while (1)
	{
		start = i;
		while (path[i] && path[i] != ':')
			i++;
		dirs[idx++] = copy_part(path, start, i);
		if (!path[i])
			break ;
		i++;
	}
	dirs[idx] = NULL;
	return (dirs);
}

char	*search_dirs(char **dirs, char *cmd)
{
	char	*full;
	int		i;

	i = 0;
	while (dirs[i])
	{
		full = join_path(dirs[i], cmd);
		if (full && access(full, X_OK) == 0)
		{
			free_args(dirs);
			return (full);
		}
		free(full);
		i++;
	}
	free_args(dirs);
	return (NULL);
}

char	*find_in_path(t_minishell *sh, char *cmd)
{
	char	*path_env;
	char	**dirs;

	if (cmd == NULL)
	{
		free_minishell(sh);
		exit(0);
	}
	if (!cmd || ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_env_value(sh->envp, "PATH");
	if (!path_env)
		return (NULL);
	dirs = split_dirs(path_env);
	free(path_env);
	if (!dirs)
		return (NULL);
	return (search_dirs(dirs, cmd));
}
