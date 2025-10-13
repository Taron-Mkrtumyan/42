/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:09 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/10 12:33:36 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_spaces(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

int	find_closing_quote(char *line, int i, char quote)
{
	i++;
	while (line[i])
	{
		if (line[i] == '\\' && line[i + 1])
		{
			i += 2;
			continue ;
		}
		if (line[i] == quote)
			return (i);
		i++;
	}
	return (-1);
}

void	free_all(char **args, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_special(char c)
{
	return (c == ' ' || c == '\t' || c == '\0'
		|| c == '<' || c == '>' || c == '|');
}
