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

static void	child1_ps(int f1, t_cmds *cmds, int *pd)
{
	close(pd[0]);
	if (dup2 (f1, STDIN_FILENO) == -1 || dup2(pd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(2);
	}
	close(f1);
	close(pd[1]);
	execve(cmds->path1, cmds->cmd1, cmds->envp);
	perror("execve");
	exit(1);
}

static void	child2_ps(int f2, t_cmds *cmds, int *pd)
{
	close(pd[1]);
	if (dup2(f2, STDOUT_FILENO) == -1 || dup2(pd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(2);
	}
	close(f2);
	close(pd[0]);
	execve(cmds->path2, cmds->cmd2, cmds->envp);
	perror("exacve");
	exit(1);
}

static void	pipex(int f1, int f2, t_cmds *cmds)
{
	int		pd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pd) == -1)
		return (perror("Pipe"));
	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork1"));
	else if (pid1 == 0)
		child1_ps(f1, cmds, pd);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("Fork2"));
	if (pid2 == 0)
		child2_ps(f2, cmds, pd);
	close(pd[0]);
	close(pd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid1, NULL, 0);
}

static void	free_cmds(t_cmds *cmds)
{
	if (!cmds)
		return ;
	free_split(cmds->cmd1);
	free_split(cmds->cmd2);
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
	cmds->envp = envp;
	if (!cmds_init(cmds, av))
		return (free_cmds(cmds), close(f1), close(f2), 4);
	pipex(f1, f2, cmds);
	free_cmds(cmds);
	return (close(f1), close(f2), 0);
}
