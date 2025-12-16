/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:05:06 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:36:56 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_infile(t_minishell *sh, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	sh->in_fd = fd;
	return (0);
}

int	handle_outfile_trunc(t_minishell *sh, char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd < 0)
		return (1);
	sh->out_fd = fd;
	return (0);
}

int	handle_outfile_append(t_minishell *sh, char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd < 0)
		return (1);
	sh->out_fd = fd;
	return (0);
}

int	handle_heredoc(t_minishell *sh, char *delimiter)
{
	int	fd;

	fd = here_doc(delimiter, sh);
	if (fd < 0)
		return (1);
	sh->in_fd = fd;
	return (0);
}

int	process_redirection(t_minishell *sh, char *redir, char *file)
{
	if (ft_strcmp(redir, "<") == 0)
		return (handle_infile(sh, file));
	else if (ft_strcmp(redir, ">") == 0)
		return (handle_outfile_trunc(sh, file));
	else if (ft_strcmp(redir, ">>") == 0)
		return (handle_outfile_append(sh, file));
	else if (ft_strcmp(redir, "<<") == 0 && g_received_signal == 0)
		return (handle_heredoc(sh, file));
	return (0);
}
