/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:54:38 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/01/26 18:56:05 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*loc;
	size_t			i;

	total = count * size;
	if (size != 0 && total / size != count)
		return (NULL);
	loc = malloc(total);
	if (!loc)
		return (NULL);
	i = 0;
	while (i < total)
		loc[i++] = 0;
	return (loc);
}
