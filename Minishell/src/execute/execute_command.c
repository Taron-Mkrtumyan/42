/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:24 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:31:14 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_single_redir(t_minishell *sh, char *redir, char *file)
{
	int	ret;

	if (ft_strcmp(redir, "<") == 0 || ft_strcmp(redir, "<<") == 0)
	{
		if (sh->in_fd != STDIN_FILENO && sh->in_fd != -1)
		{
			close(sh->in_fd);
			sh->in_fd = STDIN_FILENO;
		}
	}
	else
	{
		if (sh->out_fd != STDOUT_FILENO && sh->out_fd != -1)
		{
			close(sh->out_fd);
			sh->out_fd = STDOUT_FILENO;
		}
	}
	ret = process_redirection(sh, redir, file);
	if (ret)
	{
		perror(file);
		return (1);
	}
	return (0);
}

int	handle_redirections(t_minishell *sh, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if ((is_redirections(sh, i) && i + 1 < end && \
is_redirections(sh, i + 1)))
		{
			sh->exit_code = 2;
			return (1);
		}
		if (is_redirections(sh, i) && i + 1 < end)
		{
			if (handle_single_redir(sh, sh->args[i], sh->args[i + 1]))
			{
				sh->exit_code = 1;
				return (1);
			}
			i += 2;
		}
		else
			i++;
	}
	return (0);
}

void	wait_for_children(t_minishell *sh)
{
	int		status;
	pid_t	wpid;
	int		sig;

	wpid = wait(&status);
	while (wpid > 0)
	{
		if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			if (sig == SIGQUIT && wpid == sh->last_pid)
				write(2, "Quit (core dumped)\n", 19);
			else if (sig == SIGINT && wpid == sh->last_pid)
				write(1, "\n", 1);
			if (wpid == sh->last_pid)
				sh->exit_code = 128 + sig;
		}
		else if (WIFEXITED(status) && wpid == sh->last_pid)
			sh->exit_code = WEXITSTATUS(status);
		wpid = wait(&status);
	}
}

void	exec_subcmd(t_minishell *sh, int start, int end, int *prev_fd)
{
	t_subprocess_data	data;
	pid_t				pid;

	sh->data = &data;
	if (!prepare_subcmd(sh, &data, start, end))
		return ;
	if (!check_double_op(sh->args))
	{
		if (!sh->is_two_operator)
			printf("two operators beside each other\n");
		sh->exit_code = 2;
		sh->is_two_operator = 1;
		free_args(data.cmd);
		return ;
	}
	pid = fork_and_exec_child(sh, &data, start);
	if (!data.has_pipe)
		sh->last_pid = pid;
	handle_parent_fds(sh, data.pipe_fd, data.has_pipe, prev_fd);
	free_args(data.cmd);
	sh->data = NULL;
}

void	execute_command(t_minishell *sh)
{
	int	i;
	int	start;
	int	prev_fd;

	if (!sh->args || !sh->args[0])
		return ;
	i = 0;
	prev_fd = -1;
	while (sh->args[i])
	{
		start = i;
		if (check_no_command_redirection(sh, start))
		{
			i += 2;
			continue ;
		}
		while (sh->args[i] && ft_strcmp(sh->args[i], "|") != 0)
			i++;
		update_fds(sh, &prev_fd);
		exec_subcmd(sh, start, i, &prev_fd);
		if (sh->args[i] && ft_strcmp(sh->args[i], "|") == 0)
			i++;
	}
	wait_for_children(sh);
}
