/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 20:28:23 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:35:39 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_no_command_redirection(t_minishell *sh, int i)
{
	if (ft_strcmp(sh->args[i], "<") == 0)
	{
		sh->exit_code = 0;
		if (access(sh->args[i + 1], F_OK) != 0)
		{
			printf("miniahell: %s: No such file or directory\n", \
sh->args[i + 1]);
			sh->exit_code = 1;
		}
		return (1);
	}
	else if (ft_strcmp(sh->args[i], ">") == 0 || \
ft_strcmp(sh->args[i], ">>") == 0)
	{
		open(sh->args[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		sh->exit_code = 0;
		return (1);
	}
	return (0);
}

char	**build_argv(char **args, int start, int end)
{
	char	**argv;
	int		i;
	int		j;

	argv = malloc(sizeof(char *) * (end - start + 1));
	if (!argv)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
	{
		if (ft_strcmp(args[i], "<") == 0
			|| ft_strcmp(args[i], ">") == 0
			|| ft_strcmp(args[i], ">>") == 0
			|| ft_strcmp(args[i], "<<") == 0)
			i += 2;
		else
			argv[j++] = ft_strdup(args[i++]);
	}
	argv[j] = NULL;
	return (argv);
}

void	validate_exec_args(t_minishell *sh, char *path, \
int start, t_subprocess_data *data)
{
	struct stat	st;

	if (data)
		printf(" ");
	if (ft_strcmp(sh->args[start], "cd") == 0 && sh->args[start + 1])
		exit_with_error(sh, " Too many arguments", 1, 0);
	if (ft_strcmp(sh->args[start], "cd") == 0 && (!path || *path == '\0'))
		exit_with_error(sh, "No such file or directory", 1, 0);
	if (!path || *path == '\0')
		exit_with_error(sh, " command not found", 127, start);
	if (stat(path, &st) == 0 && S_ISDIR(st.st_mode))
		exit_with_error(sh, " Is a directory", 126, 0);
	if (access(path, F_OK) != 0)
		exit_with_error(sh, " No such file or directory", 127, 0);
	if (access(path, X_OK) != 0)
		exit_with_error(sh, " Permission denied", 126, 0);
}
