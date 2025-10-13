/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:35 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:20:12 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

short	is_redirection(char *s)
{
	if (ft_strcmp(s, ">") == 0 || ft_strcmp(s, "<") == 0)
		return (1);
	if (ft_strcmp(s, ">>") == 0 || ft_strcmp(s, "<<") == 0)
		return (1);
	return (0);
}

short	are_double_op(char *s1, char *s2)
{
	if (is_redirection(s1) && is_redirection(s2))
		return (1);
	if (ft_strcmp(s1, "|") == 0 && ft_strcmp(s2, "|") == 0)
		return (1);
	return (0);
}

short	check_double_op(char **args)
{
	short	i;

	i = 0;
	while (args[i] && args[i + 1])
	{
		if (are_double_op(args[i], args[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	process_command(t_minishell *sh)
{
	char	*prompt;	

	prompt = get_prompt(sh);
	sh->line = readline(prompt);
	check_signal(sh);
	free(prompt);
	prompt = NULL;
	if (sh->line == NULL)
	{
		printf("exit\n");
		sh->is_running = 0;
		return ;
	}
	add_history(sh->line);
	sh->args = parse_input(sh);
	if (sh->args && sh->args[0] != NULL && valid_operators(sh))
	{
		execute_command(sh);
	}
	free_temp_data(sh);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	sh;

	(void)argc;
	(void)argv;
	init_shell(&sh);
	if (!init_env(&sh, envp))
	{
		free_array(sh.envp);
		perror("init_env");
		return (1);
	}
	setup_signals();
	while (sh.is_running)
		process_command(&sh);
	free_minishell(&sh);
	return (sh.exit_code);
}
