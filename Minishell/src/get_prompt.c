/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:26:36 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 19:07:27 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path_part(t_minishell *sh, char *cwd)
{
	char	*home;
	char	*path_part;

	home = get_env_value(sh->envp, "HOME");
	if (home && ft_strncmp(cwd, home, ft_strlen(home)) == 0)
	{
		path_part = ft_strjoin("~", cwd + ft_strlen(home));
		free(home);
		if (!path_part)
			return (NULL);
	}
	else
	{
		free(home);
		path_part = ft_strdup(cwd);
		if (!path_part)
			return (NULL);
	}
	return (path_part);
}

char	*build_prompt(char *user, char *path)
{
	char	*tmp1;
	char	*tmp2;
	char	*prompt;
	char	*final;

	tmp2 = ft_strjoin(RED, user);
	tmp1 = ft_strjoin(tmp2, ":");
	free(tmp2);
	if (!tmp1)
		return (NULL);
	tmp2 = ft_strjoin(CYAN, path);
	prompt = ft_strjoin(tmp1, tmp2);
	free(tmp2);
	free(tmp1);
	if (!prompt)
		return (NULL);
	final = ft_strjoin(prompt, RESET"$ ");
	free(prompt);
	return (final);
}

char	*get_cwd(t_minishell *sh)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	if (cwd && getcwd(cwd, PATH_MAX) != NULL)
		return (cwd);
	free(cwd);
	return (get_env_value(sh->envp, "PWD"));
}

char	*get_prompt(t_minishell *sh)
{
	char	*cwd;
	char	*user;
	char	*path;
	char	*prompt;

	cwd = get_cwd(sh);
	if (!cwd)
		return (ft_strdup("minishell$ "));
	path = get_path_part(sh, cwd);
	free(cwd);
	if (!path)
		return (ft_strdup("minishell$ "));
	user = get_env_value(sh->envp, "USER");
	if (!user)
		user = ft_strdup("user");
	prompt = build_prompt(user, path);
	free(path);
	free(user);
	if (!prompt)
		return (ft_strdup("minishell$ "));
	return (prompt);
}
