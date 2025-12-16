/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:26:48 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:41:37 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_heredoc_child(int write_fd, char *delimiter, t_minishell *sh)
{
	char	*line;

	signal(SIGINT, heredoc_sigint);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	free_minishell(sh);
	close(write_fd);
	exit(0);
}

int	here_doc(char *delimiter, t_minishell *sh)
{
	int		fds[2];
	pid_t	pid;
	int		status;

	if (pipe(fds) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		close(fds[0]);
		run_heredoc_child(fds[1], delimiter, sh);
	}
	close(fds[1]);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(fds[0]);
		return (-1);
	}
	return (fds[0]);
}

int	has_pipe(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		if (ft_strcmp(args[i++], "|") == 0)
			return (1);
	return (0);
}

int	execute_builtin(t_minishell *sh)
{
	if (!sh->args || !sh->args[0])
		return (0);
	if (ft_strcmp(sh->args[0], "cd") == 0)
		return (change_directory(sh));
	else if (ft_strcmp(sh->args[0], "exit") == 0)
		return (builtin_exit(sh));
	else if (ft_strcmp(sh->args[0], "env") == 0)
		return (builtin_env(sh));
	else if (ft_strcmp(sh->args[0], "export") == 0)
		return (builtin_export(sh));
	else if (ft_strcmp(sh->args[0], "unset") == 0)
		return (builtin_unset(sh));
	else if (ft_strcmp(sh->args[0], "echo") == 0)
		return (builtin_echo(sh));
	else if (ft_strcmp(sh->args[0], "pwd") == 0)
		return (print_working_directory(sh));
	return (0);
}

void	handle_child_fds(t_minishell *sh, int pipe_fd[2], int has_pipe)
{
	if (sh->in_fd != STDIN_FILENO)
	{
		dup2(sh->in_fd, STDIN_FILENO);
		close(sh->in_fd);
	}
	if (has_pipe)
	{
		close(pipe_fd[0]);
		if (sh->out_fd == STDOUT_FILENO)
			dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	else if (sh->out_fd != STDOUT_FILENO)
	{
		dup2(sh->out_fd, STDOUT_FILENO);
		close(sh->out_fd);
	}
}
