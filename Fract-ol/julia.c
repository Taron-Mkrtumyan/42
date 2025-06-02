/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:01:42 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/19 15:10:59 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	f_julia(int x, int y, t_fractal *vars)
{
	int		i;
	t_cplx	z;
	double	tmp;

	z.re = vars->zoom * scale(-2, 2, SIZE, x) + vars->shift_x;
	z.im = vars->zoom * scale(2, -2, SIZE, y) + vars->shift_y;
	i = -1;
	while (++i < vars->quality)
	{
		tmp = z.re;
		z.re = (z.re * z.re) - (z.im * z.im) + vars->re;
		z.im = 2 * tmp * z.im + vars->im;
		if ((z.im * z.im + z.re * z.re) > 4)
		{
			vars->color = scale(BLACK, CYAN, vars->quality, i);
			my_pixel_put(x, y, vars);
			return ;
		}
	}
	my_pixel_put(x, y, vars);
}
