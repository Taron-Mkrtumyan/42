/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:35:14 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/22 14:43:00 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch_c;
	char	*tmp_c;

	i = 0;
	ch_c = (char) c;
	tmp_c = NULL;
	while (s[i])
	{
		if (s[i] == ch_c)
			tmp_c = ((char *) &s[i]);
		i++;
	}
	if (s[i] == ch_c)
		return ((char *) &s[i]);
	return (tmp_c);
}
