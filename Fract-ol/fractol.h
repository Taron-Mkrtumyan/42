/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:11:19 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 18:31:45 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"

# define SIZE 2000
# define INVALID_INPUT "Invalid args!\n\tTry mandelbrot or julia <n1> <n2>\n"
# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF
# define ORANGE      0xFFA500
# define PURPLE      0x800080
# define PINK        0xFFC0CB
# define BROWN       0x8B4513
# define GRAY        0x808080
# define LIGHT_GRAY  0xD3D3D3
# define DARK_GRAY   0x404040

enum e_fractal_type
{
	JULIA,
	MANDELBROT,
	SIERPINSKI
};

typedef struct s_cplx
{
	double	re;
	double	im;
}	t_cplx;

typedef struct s_fractal
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
	int					max_iter;
	int					color;
	char				*name;
	enum e_fractal_type	type;
}	t_fractal;

void	render_fractal(t_fractal *vars);
bool	valid_args(int ac, char **av, t_fractal *v);
void	vars_init(t_fractal *vars);
void	ft_putstr(char *s);
void	f_mandelbrot(int x, int y, t_fractal *vars);
void	my_pixel_put(int x, int y, t_fractal *vars);
double	scale(double n1, double n2, double o, double i);

#endif
