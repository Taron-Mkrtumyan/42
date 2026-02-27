/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 20:20:50 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/24 21:46:10 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	integer_part(char *tmp)
{
	int	res;

	res = 0;
	if (*tmp == '.')
		return (0);
	while (*tmp && ft_isdigit(*tmp))
	{
		res = res * 10 + (*tmp - '0');
		tmp++;
	}
	return (res);
}

static double	decimal_part(char *tmp)
{
	double	res;
	double	div;

	res = 0.0;
	div = 10.0;
	if (!(*tmp))
		return (0.0);
	while (*tmp && ft_isdigit(*tmp))
	{
		res += (*tmp - '0') / div;
		div *= 10;
		tmp++;
	}
	return (res);
}

double	ft_strtod_next(char *tmp)
{
	double	res;

	res = 0.0;
	res += (double)integer_part(tmp);
	while (*tmp && *tmp != '.')
		tmp++;
	if (*tmp == '.')
		res += decimal_part(++tmp);
	return (res);
}

double	ft_strtod(const char *s)
{
	double	res;
	char	sign;
	char	*tmp;

	res = 0.0;
	sign = 1;
	if (!s || !s[0])
		return (0.0);
	tmp = (char *)s;
	while (*tmp && ft_isspace(*tmp))
		tmp++;
	if (*tmp == '\0')
		return (0.0);
	if (*tmp == '-')
		sign = -1;
	tmp += (*tmp == '-' || *tmp == '+');
	if (*tmp == '\0')
		return (0.0);
	res = ft_strtod_next(tmp) * sign;
	return (res);
}
