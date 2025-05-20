/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:43:25 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/19 16:44:15 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	is_double(const char *str)
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
	return (true);
}

static bool	is_mandelbrot(const char *s)
{
	int		i;
	char	*type;

	type = "mandelbrot";
	i = 0;
	while (s[i])
	{
		if (!(s[i] == type[i] || (s[i] - 32) == type[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_sierpinski(const char *s)
{
	int		i;
	char	*type;

	type = "sierpinski";
	i = 0;
	while (s[i])
	{
		if (!(s[i] == type[i] || (s[i] - 32) == type[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	is_julia(const char *s)
{
	int		i;
	char	*type;

	type = "julia";
	i = 0;
	while (s[i])
	{
		if (!(s[i] == type[i] || (s[i] - 32) == type[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	valid_args(int ac, char **av, t_fractal *v)
{
	if (ac == 1 || ac > 4)
		return (false);
	if (ac == 2 && (!is_mandelbrot(av[1]) && !is_sierpinski(av[1])))
		return (false);
	if (ac == 2)
	{
		if (is_mandelbrot(av[1]))
		{
			v->type = MANDELBROT;
			v->name = "MandelBrot :)";
		}
		else
		{
			v->type = SIERPINSKI;
			v->name = "SierPinsky .-.";
		}
		return (true);
	}
	if (is_julia(av[1]) && ac != 4)
		return (false);
	if (!is_double(av[3]) && !is_double(av[4]))
		return (false);
	v->type = JULIA;
	return (true);
}
