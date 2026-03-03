/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:47 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/27 17:52:29 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_uchar(char *str)
{
	unsigned char	res;
	unsigned char	limit;
	int				i;

	if (!str || !str[0])
		return (false);
	i = 0;
	res = 0;
	limit = UCHAR_MAX / 10;
	if (str[i] == '-')
		return (false);
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		if (res > limit || (res == limit && (unsigned char)(str[i] - \
'0') > UCHAR_MAX % 10))
			return (false);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (true);
}

bool	is_valid_obj_name(char *line)
{
	if (line[0] && line[0] >= 'A' && line[0] <= 'Z')
	{
		if (line[1] && ft_isspace(line[1]))
			return (true);
		else
			return (false);
	}
	else if (line[0] && line[0] >= 'a' && line[0] <= 'z')
	{
		if (line[1] && line[1] >= 'a' && line[1] <= 'z')
		{
			if (line[2] && ft_isspace(line[2]))
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}
