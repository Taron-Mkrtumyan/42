/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:29:19 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/09/15 17:41:58 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_working_directory(t_minishell *sh)
{
	char	*path;
	char	*additional_path;

	path = getcwd(NULL, 0);
	if (!path)
	{
		additional_path = get_env_value(sh->envp, "PWD");
		if (ft_strcmp(additional_path, "") == 0)
		{
			ft_putendl_fd("pwd: error retrieving current directory: getcwd: \
cannot access parent directories: No such file or directory", \
STDERR_FILENO);
			return (0);
		}
		ft_putendl_fd(additional_path, sh->out_fd);
		free(additional_path);
		return (1);
	}
	ft_putendl_fd(path, sh->out_fd);
	free(path);
	sh->exit_code = 0;
	return (1);
}
