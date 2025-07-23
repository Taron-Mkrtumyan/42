/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:43:26 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/06/13 21:09:50 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

static int	ft_strcmp(char *s1, char *s2)
{
	if (!s1)
		return (*s2);
	if (!s2)
		return (*s1);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

static bool	is_uint(char *n)
{
	int	i;

	i = 0;
	if (n[0] && n[0] == '0')
		return (false);
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9'))
			return (0);
		i++;
	}
	if (i < 10)
		return (1);
	if (i > 10)
		return (0);
	if (ft_strcmp("4294967295", n) > 0)
		return (0);
	return (true);
}

static bool	are_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < 5 + (ac == 6))
	{
		if (!is_uint(av[i]))
			return (false);
	}
	return (true);
}

bool	valid_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (false);
	if (!av || !av[1] || !av[2] || !av[3] || !av[4])
		return (false);
	if (ac == 6 && !av[5])
		return (false);
	if (!are_int(ac, av))
		return (false);
	return (true);
}
