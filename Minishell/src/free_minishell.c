/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:28 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:38:09 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_temp_data(t_minishell *sh)
{
	free_args(sh->args);
	sh->args = NULL;
	free(sh->line);
	sh->line = NULL;
	sh->data = NULL;
	sh->is_two_operator = 0;
}

void	free_minishell(t_minishell *sh)
{
	if (!sh)
		return ;
	free(sh->oldpwd);
	sh->oldpwd = NULL;
	free(sh->path);
	sh->path = NULL;
	free(sh->line);
	sh->line = NULL;
	if (sh->args)
		free_array(sh->args);
	sh->args = NULL;
	if (sh->envp)
		free_array(sh->envp);
	sh->envp = NULL;
	if (sh->data)
	{
		free_array(sh->data->cmd);
		sh->data->cmd = NULL;
	}
	sh->in_fd = 0;
	sh->out_fd = 1;
}
