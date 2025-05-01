/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:33:03 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/29 16:46:56 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int	len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = len(dest);
	src_len = len(src);
	if (size <= dest_len)
		return (size + src_len);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (dest_len != 0)
		dest[i] = '\0';
	return (dest_len + src_len);
}

/*int main(){
	char* src = " .-. ";
	char dest[100] = "123456789";

//	printf("%d\n", ft_strlcat(dest, src, 10));
//	printf("%s\n", dest);

	printf("%lu\n", strlcat(dest, src, 10));
	printf("%s\n", dest);
	return (0);
}*/
