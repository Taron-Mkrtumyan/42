/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:47 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:40:24 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_ulong(char *str)
{
	unsigned long	res;
	unsigned long	limit;
	int				i;

	if (!str || !str[0])
		return (false);
	i = 0;
	res = 0;
	limit = ULONG_MAX / 10;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		if (res > limit || (res == limit && (unsigned long)(str[i] - \
'0') > ULONG_MAX % 10))
			return (false);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (true);
}
