/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:21 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/29 17:30:53 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_with_error(t_minishell *sh, char *msg, int status, int num)
{
	char	*full_msg;

	if (ft_strcmp(msg, " command not found") == 0 && sh->args[0])
	{
		full_msg = ft_strjoin(sh->args[num], ": command not found");
		ft_putendl_fd(full_msg, STDERR_FILENO);
		free(full_msg);
	}
	else if (ft_strcmp(msg, "No such file or directory") == 0 && sh->args[0])
	{
		full_msg = ft_strjoin(sh->args[0], ": No such file or directory");
		ft_putendl_fd(full_msg, STDERR_FILENO);
		free(full_msg);
	}
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	free_minishell(sh);
	if (status == -1)
		exit(sh->exit_code);
	exit(status);
	return (1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		free(args[i++]);
	free(args);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*join_path(char *dir, char *cmd)
{
	char	*path;
	size_t	len;

	len = strlen(dir) + strlen(cmd) + 2;
	path = malloc(len);
	if (!path)
		return (NULL);
	ft_strcpy(path, dir);
	ft_strcat(path, "/");
	ft_strcat(path, cmd);
	return (path);
}
