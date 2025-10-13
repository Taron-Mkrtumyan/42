/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:13 by gkankia           #+#    #+#             */
/*   Updated: 2025/06/19 16:54:10 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_segment(char *line, int start, int end)
{
	char	*segment;
	int		len;
	int		j;

	len = end - start;
	segment = malloc(len + 1);
	if (!segment)
		return (NULL);
	j = 0;
	while (start < end)
		segment[j++] = line[start++];
	segment[j] = '\0';
	return (segment);
}

char	*get_env_value(char **envp, char *name)
{
	int		i;
	size_t	len;

	if (!name || !*name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (ft_strdup(envp[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}

char	*parse_dollar(t_minishell *sh, int *i)
{
	int		start;
	int		len;
	char	*name;
	char	*value;

	(*i)++;
	if (sh->line[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->exit_code));
	}
	start = *i;
	while (sh->line[*i] && (ft_isalnum(sh->line[*i]) || sh->line[*i] == '_'))
		(*i)++;
	len = *i - start;
	if (len == 0)
		return (ft_strdup("$"));
	name = malloc(len + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, &sh->line[start], len + 1);
	value = get_env_value(sh->envp, name);
	free(name);
	return (value);
}

void	copy_or_empty(char *dst, char *src, size_t len)
{
	if (src)
		ft_strlcpy(dst, src, len);
	else
		dst[0] = '\0';
}

char	*str_join_free(char *s1, char *s2)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	joined = malloc(len1 + len2 + 1);
	if (!joined)
		return (NULL);
	copy_or_empty(joined, s1, len1 + 1);
	copy_or_empty(joined + len1, s2, len2 + 1);
	free(s1);
	free(s2);
	return (joined);
}
