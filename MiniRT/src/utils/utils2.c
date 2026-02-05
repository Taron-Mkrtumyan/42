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

int	is_ulong(char *str)
{
	unsigned long	res;
	unsigned long	limit;
	int				i;

	if (!str || !str[0])
		return (0);
	i = 0;
	res = 0;
	limit = ULONG_MAX / 10;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (res > limit || (res == limit && (unsigned long)(str[i] - \
'0') > ULONG_MAX % 10))
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

double	str_to_double(char *str)
{
	double	sum;
	double	prec;
	double	div;
	double	sign;

	prec = 0.0;
	div = 1.0;
	sign = 1.0;
	if (str && str[0] == '-')
		sign *= -1.0;
	sum = (double)ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str++ == '.')
	{
		while (*str >= '0' && *str <= '9')
		{
			div *= 10.0;
			prec += (*str - '0') / div;
			str++;
		}
		sum += prec * sign;
	}
	return (sum);
}

int	arr_len(char *arr[])
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}
