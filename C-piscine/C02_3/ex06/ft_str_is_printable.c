/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:52:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/24 20:26:39 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (str[0])
	{
		if (str[0] < ' ' || str[0] > '~')
			return (0);
		str++;
	}
	return (1);
}

/*int main(){
	printf("%d\n", ft_str_is_printable("`GHJKL:!  \"zxcvbnm,./ZXCVBNM<>?"));
	return 0;
}*/
