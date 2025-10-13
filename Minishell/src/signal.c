/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:40 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/29 17:30:59 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_received_signal = 0;

void	sigint_handler(int signum)
{
	g_received_signal = signum;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	heredoc_sigint(int sig)
{
	if (sig == SIGINT)
	{
		g_received_signal = 0;
		write(1, "\n", 1);
		close(STDIN_FILENO);
	}
}

void	check_signal(t_minishell *sh)
{
	if (g_received_signal == SIGINT)
		sh->exit_code = 130;
	else if (g_received_signal == SIGQUIT)
		sh->exit_code = 131;
	g_received_signal = 0;
}

void	setup_signals(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
}
