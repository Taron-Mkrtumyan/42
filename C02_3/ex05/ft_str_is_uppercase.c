/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:48:46 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/24 14:01:16 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_str_is_uppercase(char *str)
{
	bool	is_up;

	is_up = true;
	if (str[0] == '\0')
		return (1);
	else
	{
		while (str[0])
		{
			if (str[0] > 'Z' || str[0] < 'A')
				is_up = false;
			str++;
		}
	}
	if (is_up)
		return (1);
	else
		return (0);
}

/*int main(){
	printf("%d\n", ft_str_is_uppercase("ABCDZa"));
	return 0;
}*/
