/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:33 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/28 11:49:17 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

bool	is_num_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (true);
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	char_upcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	char_lowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (is_num_alpha(str[0]))
		char_upcase(&str[0]);
	while (str[i])
	{
		if (is_num_alpha(str[i - 1]))
			char_lowcase(&str[i]);
		else
			char_upcase(&str[i]);
		i++;
	}
	return (str);
}

/*int main(){
	char s[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(s));
	return 0;
}*/
