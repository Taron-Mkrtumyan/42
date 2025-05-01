/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:15:02 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/01 15:01:41 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_ps(int f1, char **cmd1, char **envp, int *pd)
{
	char	*path;

	close(pd[0]);
	dup2 (f1, 0);
	close(f1);
	dup2(pd[1], 1);
	close(pd[1]);
	path = ft_strjoin("/usr/bin/", cmd1[0]);
	if (!path)
		exit(EXIT_FAILURE);
	execve(path, cmd1, envp);
	perror("exacve");
	free(path);
	exit(EXIT_FAILURE);
}

static void	child2_ps(int f2, char **cmd2, char **envp, int *pd)
{
	char	*path;

	close(pd[1]);
	dup2(f2, 1);
	close(f2);
	dup2(pd[0], 0);
	close(pd[0]);
	path = ft_strjoin("/usr/bin/", cmd2[0]);
	if (!path)
		exit(EXIT_FAILURE);
	execve(path, cmd2, envp);
	perror("exacve");
	free(path);
	exit(EXIT_FAILURE);
}

static void	pipex(int f1, int f2, t_cmds *cmds)
{
	int		pd[2];
	pid_t	pid1;
	pid_t	pid2;

	pipe(pd);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork: "));
	else if (pid1 == 0)
		child1_ps(f1, cmds->cmd1, cmds->envp, pd);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			return (perror("Fork: "));
		if (pid2 == 0)
			child2_ps(f2, cmds->cmd2, cmds->envp, pd);
	}
	close(pd[0]);
	close(pd[1]);
	waitpid(pid1, NULL, 0);
}

static void	free_cmds(t_cmds *cmds)
{
	free(cmds->cmd1);
	free(cmds->cmd2);
	free(cmds->path1);
	free(cmds->path2);
	free(cmds);
}

int	main(int ac, char **av, char **envp)
{
	int		f1;
	int		f2;
	t_cmds	*cmds;

	if (ac != 5 && ac != 4)
		return (1);
	f1 = open (av[1], O_RDONLY);
	if (ac == 5)
		f2 = open (av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	else
		f2 = open ("file2", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (2);
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (close(f1), close(f2), 3);
	if (!cmds_init(cmds, av))
		return (3);
	if (access(cmds->path1, X_OK) || access(cmds->path2, X_OK))
		return (free_cmds(cmds), close(f1), close(f2), 4);
	cmds->envp = envp;
	pipex(f1, f2, cmds);
	free_cmds(cmds);
	return (close(f1), close(f2), 0);
}
