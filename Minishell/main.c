/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:31:39 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/30 13:18:13 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int signum)
{
	(void)signum;
	rl_replace_line("", 0);
	rl_done = 1;
}

int	empty(void)
{
	rl_redisplay();
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*line;
	char	*command;
	pid_t	pid;

	if (!data_init(&data, ac, av, envp))
		return (1);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	rl_event_hook = &empty;
	rl_catch_signals = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			return (0);
		add_history(line);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			command = ft_strjoin("/bin/", line);
			execve(command, av, envp);
			free(command);
		}
		else
		{
			wait(NULL);
		}
		free(line);
	}
	clean_all(&data);
	return (0);
}
