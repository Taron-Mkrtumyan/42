/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:44:58 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/01 19:45:16 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	is_path(char *s)
{
	if (!s || !s[0] || !s[1] || !s[2] || !s[3] || !s[4])
		return (0);
	if (s[0] == 'P' && s[1] == 'A' && s[2] == 'T' && s[3] == 'H')
	{
		if (s[4] == '=')
			return (1);
	}
	return (0);
}

static char	check_cmds(t_cmds *cmds, char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		(cmds)->path1 = ft_strjoin(paths[i], (cmds)->cmd1[0]);
		if (!access(cmds->path1, X_OK))
			break ;
		free(cmds->path1);
		cmds->path1 = NULL;
		i++;
	}
	i = 0;
	while (paths[i])
	{
		(cmds)->path2 = ft_strjoin(paths[i], (cmds)->cmd2[0]);
		if (!access(cmds->path2, X_OK))
			break ;
		free(cmds->path2);
		cmds->path2 = NULL;
		i++;
	}
	if (!cmds->path1 || !cmds->path2)
		return (0);
	return (1);
}

static char	paths_init(t_cmds *cmds)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (cmds->envp[i])
	{
		if (is_path(cmds->envp[i]))
			paths = ft_split(cmds->envp[i] + 5, ':');
		i++;
	}
	if (!paths)
		return (0);
	if (!check_cmds(cmds, paths))
	{
		free_split(paths);
		return (0);
	}
	free_split(paths);
	return (1);
}

char	cmds_init(t_cmds *cmds, char **av)
{
	(cmds)->cmd1 = ft_split(av[2], ' ');
	(cmds)->cmd2 = ft_split(av[3], ' ');
	if (!paths_init(cmds))
		return (0);
	return (1);
}
