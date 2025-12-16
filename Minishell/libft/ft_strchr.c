/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:36:32 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/25 17:23:12 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch_c;

	i = 0;
	ch_c = (char) c;
	while (s[i])
	{
		if (s[i] == ch_c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch_c)
		return ((char *) &s[i]);
	return (NULL);
}
