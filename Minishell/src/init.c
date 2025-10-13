/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:32 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:04:14 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env(t_minishell *sh, char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	sh->envp = malloc(sizeof(char *) * (i + 1));
	if (!sh->envp)
		return (0);
	i = 0;
	while (envp[i])
	{
		sh->envp[i] = ft_strdup(envp[i]);
		if (!sh->envp[i])
		{
			while (--i >= 0)
				free(sh->envp[i]);
			free(sh->envp);
			return (0);
		}
		i++;
	}
	sh->envp[i] = NULL;
	return (1);
}

void	init_shell(t_minishell *sh)
{
	sh->line = NULL;
	sh->args = NULL;
	sh->envp = NULL;
	sh->data = NULL;
	sh->path = NULL;
	sh->oldpwd = NULL;
	sh->in_fd = 0;
	sh->out_fd = 1;
	sh->is_running = 1;
	sh->exit_code = 0;
	sh->is_two_operator = 0;
	sh->last_pid = -1;
}
