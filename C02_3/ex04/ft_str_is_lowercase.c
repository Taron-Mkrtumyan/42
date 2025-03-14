/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:40:55 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/24 20:25:20 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_str_is_lowercase(char *str)
{
	bool	is_low;

	is_low = true;
	if (str[0] == '\0')
		return (1);
	else
	{
		while (str[0])
		{
			if (str[0] > 'z' || str[0] < 'a')
				is_low = false;
			str++;
		}
	}
	if (is_low)
		return (1);
	else
		return (0);
}

/*int main(){
	printf("%d\n", ft_str_is_lowercase(""));
	return 0;
}*/
