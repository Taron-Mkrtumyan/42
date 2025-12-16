/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_quoted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:54:54 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 20:13:49 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_single_quoted(char *line, int *i, int end)
{
	char	*segment;

	segment = copy_segment(line, *i, end);
	*i = end + 1;
	return (segment);
}

char	*process_dollar(t_minishell *sh, int *i, char *result)
{
	char	*var;

	var = parse_dollar(sh, i);
	if (!var)
	{
		free(result);
		return (NULL);
	}
	return (str_join_free(result, var));
}

char	*copy_double_quoted_part(t_minishell *sh, int *i, int end, char *result)
{
	while (*i < end)
	{
		if (sh->line[*i] == '\\')
			result = handle_backslash_dquote(sh, i, end, result);
		else if (sh->line[*i] == '$')
		{
			result = handle_dollar_dquote(sh, i, result);
			if (!result)
				return (NULL);
		}
		else
			result = append_segment(sh, i, end, result);
	}
	if (!result)
		return (ft_strdup(""));
	return (result);
}

char	*copy_double_quoted(t_minishell *sh, int *i, int end)
{
	char	*result;

	result = copy_double_quoted_part(sh, i, end, NULL);
	*i = end + 1;
	return (result);
}

char	*copy_quoted_arg(t_minishell *sh, int *i)
{
	char	quote;
	int		end;

	quote = sh->line[*i];
	end = find_closing_quote(sh->line, *i, quote);
	if (end == -1)
	{
		ft_putendl_fd("Please close the scopes", STDERR_FILENO);
		return (NULL);
	}
	*i = *i + 1;
	if (quote == '\'')
		return (copy_single_quoted(sh->line, i, end));
	return (copy_double_quoted(sh, i, end));
}
