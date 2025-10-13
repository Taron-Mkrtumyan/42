/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:42:19 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 14:51:06 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_infiles(char **args, t_minishell *sh)
{
	int		i;
	int		fd;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], "<") == 0 && args[i + 1])
		{
			fd = open(args[i + 1], O_RDONLY);
			if (fd == -1)
			{
				ft_putstr_fd("minishell: ", STDERR_FILENO);
				perror(args[i + 1]);
				sh->exit_code = 1;
				return (0);
			}
			close(fd);
			i++;
		}
		i++;
	}
	return (1);
}

char	*copy_escaped_char(char *line, int *i)
{
	char	*res;

	if (!line[*i + 1])
	{
		(*i)++;
		return (ft_strdup("\\"));
	}
	res = malloc(2);
	if (!res)
		return (NULL);
	res[0] = line[*i + 1];
	*i += 2;
	return (res);
}

char	*append_segment(t_minishell *sh, int *i, int end, char *result)
{
	int		start;
	char	*segment;

	start = *i;
	while (*i < end && sh->line[*i] != '$' && sh->line[*i] != '\\')
		(*i)++;
	segment = copy_segment(sh->line, start, *i);
	if (!segment)
		return (free(result), NULL);
	return (str_join_free(result, segment));
}

char	*handle_backslash_dquote(t_minishell *sh, int *i, int end, char *result)
{
	char	buf[3];

	if ((*i + 1 < end) && (sh->line[*i + 1] == '$' || \
sh->line[*i + 1] == '"' || sh->line[*i + 1] == '\\'))
	{
		buf[0] = sh->line[*i + 1];
		buf[1] = '\0';
		*i += 2;
	}
	else
	{
		buf[0] = '\\';
		buf[1] = sh->line[*i + 1];
		buf[2] = '\0';
		*i += 2;
	}
	return (str_join_free(result, ft_strdup(buf)));
}

char	*handle_dollar_dquote(t_minishell *sh, int *i, char *result)
{
	result = process_dollar(sh, i, result);
	if (!result)
		return (NULL);
	return (result);
}
