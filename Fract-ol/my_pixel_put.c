/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:44:21 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 19:55:26 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_fractal *vars)
{
	int	offset;

	offset = (y * vars->line_len) + x * (vars->bpp / 8);
	*(unsigned int *)(vars->addr + offset) = vars->color;
}
