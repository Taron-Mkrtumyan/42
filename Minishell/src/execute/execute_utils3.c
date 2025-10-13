/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:50:36 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 19:38:26 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_cmd(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "cd") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0)
		return (1);
	return (0);
}

void	restore_fds(t_minishell *sh, int saved_stdin, int saved_stdout)
{
	if (saved_stdin >= 0)
	{
		dup2(saved_stdin, STDIN_FILENO);
		close(saved_stdin);
	}
	if (saved_stdout >= 0)
	{
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
	}
	if (sh->in_fd != STDIN_FILENO)
	{
		close(sh->in_fd);
		sh->in_fd = STDIN_FILENO;
	}
	if (sh->out_fd != STDOUT_FILENO)
	{
		close(sh->out_fd);
		sh->out_fd = STDOUT_FILENO;
	}
}

int	prepare_builtin_execution(t_builtin_exec *exec)
{
    exec->saved_stdin = dup(STDIN_FILENO);
    exec->saved_stdout = dup(STDOUT_FILENO);
    exec->cmd_argv = build_argv(exec->sh->args, exec->start, exec->end);
    if (!exec->cmd_argv || !exec->cmd_argv[0])
        return (1);
    if (handle_redirections(exec->sh, exec->start, exec->end))
        return (1);
    if (exec->sh->in_fd != STDIN_FILENO)
    {
        dup2(exec->sh->in_fd, STDIN_FILENO);
        close(exec->sh->in_fd);           // <-- ADD THIS LINE
        exec->sh->in_fd = STDIN_FILENO;   // <-- AND THIS LINE
    }
    if (exec->sh->out_fd != STDOUT_FILENO)
    {
        dup2(exec->sh->out_fd, STDOUT_FILENO);
        close(exec->sh->out_fd);
        exec->sh->out_fd = STDOUT_FILENO;
    }
    return (0);
}

void	execute_builtin_in_parent(t_minishell *sh, int start, int end)
{
	t_builtin_exec	exec;
	char			**old_args;

	exec.sh = sh;
	exec.start = start;
	exec.end = end;
	if (prepare_builtin_execution(&exec))
	{
		free_args(exec.cmd_argv);
		restore_fds(sh, exec.saved_stdin, exec.saved_stdout);
		return ;
	}
	old_args = sh->args;
	sh->args = exec.cmd_argv;
	execute_builtin(sh);
	sh->args = old_args;
	restore_fds(sh, exec.saved_stdin, exec.saved_stdout);
	free_args(exec.cmd_argv);
}

void	handle_parent_fds(t_minishell *sh, int pipe_fd[2],\
	int has_pipe, int *prev_fd)
{
	if (sh->in_fd != STDIN_FILENO)
		close(sh->in_fd);
	if (sh->out_fd != STDOUT_FILENO)
		close(sh->out_fd);
	if (has_pipe)
	{
		close(pipe_fd[1]);
		*prev_fd = pipe_fd[0];
	}
}
