/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:59:55 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/01/31 14:36:35 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	ctr;

	ctr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			ctr++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ctr);
}

static int	add_word(char **words, const char *s, int i, int l)
{
	int	ctr;

	ctr = 0;
	while (words[ctr])
		ctr++;
	words[ctr] = ft_substr(s, i, l);
	if (!words[ctr])
	{
		while (ctr--)
			free(words[ctr]);
		free(words);
		return (0);
	}
	return (1);
}

static int	solve(char **words, const char *s, char c)
{
	int	i;
	int	l;

	i = 0;
	while (s[i])
	{
		l = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + l] && s[i + l] != c)
			l++;
		if (s[i])
		{
			if (!(add_word(words, s, i, l)))
				return (0);
			i += l;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!words)
		return (NULL);
	if (!solve(words, s, c))
		return (NULL);
	return (words);
}
