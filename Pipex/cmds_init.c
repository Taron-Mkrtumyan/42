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

int	cmds_init(t_cmds *cmds, char **av)
{
	cmds->cmd1 = ft_split(av[2], ' ');
	if (!cmds->cmd1)
		return (0);
	cmds->cmd2 = ft_split(av[3], ' ');
	if (!cmds->cmd2)
	{
		free(cmds->cmd1);
		return (0);
	}
	cmds->path1 = ft_strjoin("/usr/bin/", cmds->cmd1[0]);
	if (!cmds->path1)
	{
		free(cmds->cmd1);
		free(cmds->cmd1);
		return (0);
	}
	cmds->path2 = ft_strjoin("/usr/bin/", cmds->cmd2[0]);
	if (!cmds->path2)
	{
		free(cmds->cmd1);
		free(cmds->cmd1);
		free(cmds->path2);
		return (0);
	}
	return (1);
}
