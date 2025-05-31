/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:53:30 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 18:55:41 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double n1, double n2, double o, double i)
{
	return ((n2 - n1) * i / o + n1);
}

double	atod(char *s)
{
	double	res;
	double	power;
	short	sign;

	power = 1;
	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s != '.')
		res = 10 * res + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		power /= 10;
		res += power * (*s++ - '0');
	}
	return (res * sign);
}
