/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_unquoted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:01 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/09 21:28:46 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_dollar(t_minishell *sh, int *i, char *result)
{
	char	*tmp;

	tmp = parse_dollar(sh, i);
	if (!tmp)
	{
		free(result);
		return (NULL);
	}
	return (str_join_free(result, tmp));
}

char	*handle_backslash(t_minishell *sh, int *i, char *result)
{
	char	buf[2];
	char	*tmp;

	(*i)++;
	if (sh->line[*i])
	{
		buf[0] = sh->line[*i];
		buf[1] = '\0';
		tmp = ft_strdup(buf);
		if (!tmp)
			return (free(result), NULL);
		result = str_join_free(result, tmp);
		(*i)++;
	}
	else
		result = str_join_free(result, ft_strdup("\\"));
	return (result);
}

char	*handle_regular_char(t_minishell *sh, int *i, char *result)
{
	char	buf[2];
	char	*tmp;

	buf[0] = sh->line[*i];
	buf[1] = '\0';
	tmp = ft_strdup(buf);
	if (!tmp)
		return (free(result), NULL);
	result = str_join_free(result, tmp);
	(*i)++;
	return (result);
}

char	*copy_unquoted_arg(t_minishell *sh, int *i)
{
	char	*result;

	result = NULL;
	while (sh->line[*i] && !is_special(sh->line[*i]) && !is_quote(sh->line[*i]))
	{
		if (sh->line[*i] == '$')
			result = handle_dollar(sh, i, result);
		else if (sh->line[*i] == '\\')
			result = handle_backslash(sh, i, result);
		else
			result = handle_regular_char(sh, i, result);
		if (!result)
			return (NULL);
	}
	return (result);
}
