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
		vars->color = RED;
		f_mandelbrot(x, y, vars);
	}
	else if (vars->type == SIERPINSKI)
	{
		return ;
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
