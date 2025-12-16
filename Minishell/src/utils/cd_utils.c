/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:50:17 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 20:07:14 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_existing_var(char **env, const char *key,
	char *new_entry, int len)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
		{
			free(env[i]);
			env[i] = new_entry;
			return (1);
		}
		i++;
	}
	return (0);
}

int	append_new_var(char ***envp, char *new_entry, int size)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
		return (free(new_entry), 0);
	i = 0;
	while (i < size)
	{
		new_env[i] = (*envp)[i];
		i++;
	}
	new_env[size] = new_entry;
	new_env[size + 1] = NULL;
	free(*envp);
	*envp = new_env;
	return (1);
}

int	set_env_value(char ***envp, const char *key, const char *value)
{
	char	*tmp;
	char	*new_entry;
	int		len;
	int		size;

	if (!key || !value)
		return (0);
	len = ft_strlen(key);
	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (0);
	new_entry = ft_strjoin(tmp, value);
	free(tmp);
	if (!new_entry)
		return (0);
	if (update_existing_var(*envp, key, new_entry, len))
		return (1);
	size = 0;
	while (*envp && (*envp)[size])
		size++;
	return (append_new_var(envp, new_entry, size));
}

void	update_fds(t_minishell *sh, int *prev_fd)
{
	if (*prev_fd < 0)
		sh->in_fd = STDIN_FILENO;
	else
		sh->in_fd = *prev_fd;
	sh->out_fd = STDOUT_FILENO;
}

int	is_redirections(t_minishell *sh, int i)
{
	if (ft_strcmp(sh->args[i], "<") == 0
		|| ft_strcmp(sh->args[i], ">") == 0
		|| ft_strcmp(sh->args[i], ">>") == 0
		|| ft_strcmp(sh->args[i], "<<") == 0)
		return (1);
	return (0);
}
