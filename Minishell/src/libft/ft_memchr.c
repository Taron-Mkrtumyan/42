/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:58:23 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/25 15:42:07 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c_ch;

	i = 0;
	str = (unsigned char *) s;
	c_ch = (unsigned char) c;
	while (i < n)
	{
		if (str[i] == c_ch)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
