/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:32:34 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/25 15:28:56 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	words_count(const char *s, char c)
{
	size_t	count;
	int		in_word;
	int		i;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*str_copy;

	str_copy = (char *)malloc(sizeof(char) * (n + 1));
	if (!str_copy)
		return (0);
	i = 0;
	while (i < n)
	{
		str_copy[i] = src[i];
		i++;
	}
	str_copy[n] = '\0';
	return (str_copy);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	size_t		count_words;
	size_t		i;
	const char	*start;

	count_words = words_count(s, c);
	res = malloc(sizeof(char *) * (count_words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			res[i] = ft_strndup(start, s - start);
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

/*#include <stdio.h>
int	main()
{
	char *str = "Hello World, hihi";
	char c = ' ';
	char **words = ft_split(str, c);

	for (int i = 0; i < 3; i++)
	{
		printf("{%s}\n", words[i]);
	}
	return (0);
}*/
