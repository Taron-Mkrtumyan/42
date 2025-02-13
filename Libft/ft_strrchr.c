/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:59 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/01/24 12:45:57 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			found = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	if (found == -1)
		return (NULL);
	return ((char *)(s + found));
}
