/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:48:33 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 17:49:09 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_pixel(int x, int y, t_fractal *vars)
{
	if (vars->type == MANDELBROT)
	{
		vars->color = BLACK;
		f_mandelbrot(x, y, vars);
	}
	else if (vars->type == BURNING_SHIP)
	{
		vars->color = BLACK;
		f_burning_ship(x, y, vars);
	}
	else if (vars->type == JULIA)
	{
		vars->color = CYAN;
		f_julia(x, y, vars);
	}
}

void	render_fractal(t_fractal *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
		{
			handle_pixel(x, y, vars);
		}
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
