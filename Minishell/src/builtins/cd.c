/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:27:17 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 21:11:31 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_pwd(t_minishell *sh, char *oldpwd, char *newpwd)
{
	if (sh->oldpwd)
		set_env_value(&sh->envp, "OLDPWD", oldpwd);
	if (newpwd)
		set_env_value(&sh->envp, "PWD", newpwd);
}

char	*get_cd_target(t_minishell *sh, char *oldpwd)
{
	char	*target;
	char	*home;

	home = NULL;
	if (!sh->args[1] || ft_strcmp(sh->args[1], "~") == 0)
	{
		home = get_env_value(sh->envp, "HOME");
		if (!home)
			return (NULL);
		return (home);
	}
	if (sh->args[2])
		return (NULL);
	if (ft_strcmp(sh->args[1], "-") == 0)
	{
		if (!oldpwd)
			return (NULL);
		ft_putendl_fd(oldpwd, STDOUT_FILENO);
		return (ft_strdup(oldpwd));
	}
	target = ft_strdup(sh->args[1]);
	return (target);
}

int	do_chdir(t_minishell *sh, char *target, char *cwd_before)
{
	char	*cwd_after;

	if (chdir(target) != 0)
	{
		perror("minishell: cd");
		free(target);
		free(cwd_before);
		sh->exit_code = 1;
		return (0);
	}
	cwd_after = getcwd(NULL, 0);
	if (!cwd_after)
		cwd_after = ft_strdup(target);
	update_env_pwd(sh, cwd_before, cwd_after);
	free(cwd_after);
	return (1);
}

int	change_directory(t_minishell *sh)
{
	char		*target;
	char		*cwd_before;

	target = get_cd_target(sh, sh->oldpwd);
	if (!target)
	{
		if (sh->args[2])
			ft_putendl_fd("minishell: cd: too many arguments", STDERR_FILENO);
		else
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
		sh->exit_code = 1;
		return (0);
	}
	cwd_before = get_env_value(sh->envp, "PWD");
	if (!cwd_before)
		cwd_before = getcwd(NULL, 0);
	if (!do_chdir(sh, target, cwd_before))
		return (0);
	free(sh->oldpwd);
	sh->oldpwd = ft_strdup(cwd_before);
	free(cwd_before);
	free(target);
	sh->exit_code = 0;
	return (1);
}
