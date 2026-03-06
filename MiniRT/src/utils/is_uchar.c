/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_uchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:14:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 19:14:33 by tmkrtumy         ###   ########.fr       */
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
