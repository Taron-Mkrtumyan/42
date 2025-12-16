/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:27:03 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/04 20:24:47 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process_builton(t_minishell *sh, t_subprocess_data *data)
{
	free_args(sh->args);
	sh->args = data->cmd;
	if (!execute_builtin(sh))
		exit(sh->exit_code);
	sh->args = NULL;
	free_minishell(sh);
	exit(0);
}

void	child_process(t_minishell *sh, t_subprocess_data *data, \
int start)
{
	int	fd;

	signal(SIGPIPE, SIG_IGN);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	handle_child_fds(sh, data->pipe_fd, data->has_pipe);
	if (data->redir_error)
		exit(1);
	if (is_builtin_cmd(data->cmd[0]))
		child_process_builton(sh, data);
	sh->path = find_in_path(sh, data->cmd[0]);
	validate_exec_args(sh, sh->path, start, data);
	if (!sh->path)
		exit_with_error(sh, "No such file or directory", 127, 0);
	free_args(sh->args);
	fd = open("/dev/null", O_WRONLY);
	if (fd >= 0)
	{
		dup2(fd, STDERR_FILENO);
		close(fd);
	}
	execve(sh->path, data->cmd, sh->envp);
	free(sh->path);
	exit_with_error(sh, "execve", 1, 0);
}

pid_t	fork_and_exec_child(t_minishell *sh, \
t_subprocess_data *data, int start)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_with_error(sh, "fork", 1, 0);
	if (pid == 0)
	{
		if (data->redir_error)
			exit(1);
		child_process(sh, data, start);
		free_minishell(sh);
	}
	return (pid);
}

int	init_subcmd(t_minishell *sh, t_subprocess_data *data,
	int start, int end)
{
	data->cmd = build_argv(sh->args, start, end);
	if (!data->cmd)
	{
		free_args(data->cmd);
		return (0);
	}
	data->has_pipe = (sh->args[end] && ft_strcmp(sh->args[end], "|") == 0);
	if (is_builtin_cmd(data->cmd[0]) && !data->has_pipe)
	{
		execute_builtin_in_parent(sh, start, end);
		free_args(data->cmd);
		return (0);
	}
	if (data->has_pipe && pipe(data->pipe_fd) == -1)
	{
		free_args(data->cmd);
		exit_with_error(sh, "pipe", 1, 0);
	}
	return (1);
}

int	prepare_subcmd(t_minishell *sh, t_subprocess_data *data,
	int start, int end)
{
	if (!init_subcmd(sh, data, start, end))
		return (0);
	if (handle_redirections(sh, start, end))
	{
		data->redir_error = 1;
		free_args(data->cmd);
		if (data->has_pipe)
		{
			close(data->pipe_fd[0]);
			close(data->pipe_fd[1]);
		}
		return (0);
	}
	data->redir_error = 0;
	return (1);
}
