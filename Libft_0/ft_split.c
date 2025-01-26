/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:59:55 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/01/24 14:33:55 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	ctr;

	ctr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		ctr++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ctr);
}

int	add_word(char **words, const char *s, int l, int r)
{
	int	i;
	int	ctr;

	ctr = 0;
	while (words[ctr] != 0)
		ctr++;
	words[ctr] = (char *)malloc(sizeof(char) * (r - l + 1));
	if (!words[ctr])
	{
		while (ctr)
		{
			free(words[ctr]);
			ctr--;
		}
		free(words);
		return (0);
	}
	i = 0;
	while (l + i < r)
	{
		words[ctr][i] = s[l + i];
		i++;
	}
	words[ctr][i] = '\0';
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		l;
	int		r;
	int		ctr;

	words = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	l = 0;
	ctr = 0;
	while (s[l])
	{
		words[ctr++] = 0;
		while (s[l] && s[l] == c)
			l++;
		r = l + 1;
		while (s[r] && s[r] != c)
			r++;
		if (!s[l])
			break ;
		if (add_word(words, s, l, r) == 0)
			return (NULL);
		l = r;
	}
	return (words);
}
