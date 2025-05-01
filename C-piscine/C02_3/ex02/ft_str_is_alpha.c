/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:56:01 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/28 11:50:25 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	while (str[0])
	{
		if (str[0] < 'A' || str[0] > 'z' || (str[0] > 'Z' && str[0] < 'a'))
			return (0);
		str++;
	}
	return (1);
}

/*int main(){
	printf("%d\n", ft_str_is_alpha("abcdezHAZMSDbjfrrpqolo@qwindm"));
	return 0;
}*/
