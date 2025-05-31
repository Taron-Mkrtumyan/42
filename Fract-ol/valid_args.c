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

static bool	is_mandelbrot(const char *s, t_fractal *vars)
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
	vars->type = MANDELBROT;
	vars->name = "MandelBrot :)";
	return (true);
}

static bool	is_ship(const char *s, t_fractal *vars)
{
	int		i;
	char	*type;

	type = "burning_ship";
	i = 0;
	while (s[i])
	{
		if (!(s[i] == type[i] || (s[i] - 32) == type[i]))
			return (false);
		i++;
	}
	vars->type = BURNING_SHIP;
	vars->name = "Burning Ship .-.";
	return (true);
}

static bool	is_julia(const char *s, t_fractal *vars)
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
	vars->type = JULIA;
	vars->name = "So I Sing a Song of Love, Julia";
	return (true);
}

bool	valid_args(int ac, char **av, t_fractal *vars)
{
	if (ac == 1 || ac > 4)
		return (false);
	if (ac == 2 && (!is_mandelbrot(av[1], vars) && !is_ship(av[1], vars)))
		return (false);
	if (ac == 2)
		return (true);
	if (is_julia(av[1], vars) && ac != 4)
		return (false);
	if (!is_double(av[2]) && !is_double(av[3]))
		return (false);
	vars->re = atod(av[2]);
	vars->im = atod(av[3]);
	return (true);
}
