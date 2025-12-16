/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:21:23 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/24 16:18:40 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_tmp;
	char	*src_tmp;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dst_tmp = (char *) dst;
	src_tmp = (char *) src;
	i = 0;
	if (dst_tmp > src_tmp)
	{
		while (len-- > 0)
			dst_tmp[len] = src_tmp[len];
	}
	else
	{
		while (i < len)
		{
			dst_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dst);
}
