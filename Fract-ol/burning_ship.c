/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:01:42 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/19 15:10:59 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_burning_ship(int x, int y, t_fractal *vars)
{
	int		i;
	t_cplx	z;
	t_cplx	c;
	double	tmp;

	z.re = 0.0;
	z.im = 0.0;
	c.re = vars->zoom * scale(-2, 2, SIZE, x) + vars->shift_x;
	c.im = vars->zoom * scale(2, -2, SIZE, y) + vars->shift_y;
	i = -1;
	while (++i < vars->quality)
	{
		tmp = z.re;
		z.re = fabs(z.re * z.re - z.im * z.im) + c.re;
		z.im = 2 * tmp * z.im + c.im;
		if ((z.im * z.im + z.re * z.re) > 4)
		{
			vars->color = scale(BLACK, RED, vars->quality, i);
			my_pixel_put(x, y, vars);
			return ;
		}
	}
	my_pixel_put(x, y, vars);
}
