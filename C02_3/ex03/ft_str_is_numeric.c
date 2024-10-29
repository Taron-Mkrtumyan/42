/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:29:52 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/24 20:24:59 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_str_is_numeric(char *str)
{
	bool	is_digit;

	is_digit = true;
	if (str[0] == '\0')
		return (1);
	else
	{
		while (str[0])
		{
			if (!(str[0] <= '9' && str[0] >= '0'))
				is_digit = false;
			str++;
		}
	}
	if (is_digit)
		return (1);
	else
		return (0);
}

/*int main(){
	printf("%d\n", ft_str_is_numeric(""));
	return 0;
}*/
