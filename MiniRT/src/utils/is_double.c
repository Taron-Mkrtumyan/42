/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 19:31:45 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/02 19:41:32 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	double_length(double num)
{
	int	ctr;

	ctr = 0;
	while (num >= 1.0)
	{
		++ctr;
		num /= 10.0;
	}
	return (ctr);
}

static bool	compare_digits(char *s)
{
	if (ft_strncmp(s, "1797693134862315708145274237317043567980705", 42) > 0)
		return (false);
	return (true);
}

static bool	is_in_double_range(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (i < double_length(DBL_MAX))
		return (true);
	if (i > double_length(DBL_MAX))
		return (false);
	return (compare_digits(s));
}

bool	is_double(char *str)
{
	int		i;
	bool	has_digits;

	i = 0;
	has_digits = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_digits = true;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_digits = true;
		i++;
	}
	if (!has_digits)
		return (false);
	if (str[i] != '\0')
		return (false);
	return (is_in_double_range(str));
}

/*
int main ()
{
	printf("%d\n", is_double("17976931348623157081452742"));
	return (0);
}
*/