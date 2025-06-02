/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:11:19 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/21 21:40:27 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// INSTRUCTIONS

// make m			- execute mandelbrot
// make j 			- execute julia
// make s 			- execute burning ship
// make vm, vj, vs	- above with valgrind

// + 				- increase zoom
// - 				- decrease zoom

// w / ↑ 			- move up
// a / ← 			- move left
// s / ↓ 			- move down
// d / → 			- move right

// space 			- change color + better quality
// j 				- rotate julia
// Esc				- exit

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define SIZE		2000
# define QUALITY	0
# define SMOOTH		0.2

# define NP_PLUS	65451
# define NP_MINUS	65453

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define PINK		0xFFC0CB
# define BROWN		0x8B4513
# define GRAY		0x808080
# define LIGHT_GRAY	0xD3D3D3
# define DARK_GRAY	0x404040

# define INVALID_INPUT " Invalid args!\n\n\
 Try:\n\
\t mandelbrot\n\
\t julia <real> <i>\n\
\t burning_ship\n\n"

enum e_fractal_type
{
	JULIA,
	MANDELBROT,
	BURNING_SHIP
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
	int					quality;
	double				shift_x;
	double				shift_y;
	double				zoom;
	double				re;
	double				im;
	double				a;
	enum e_fractal_type	type;
}	t_fractal;

void	render_fractal(t_fractal *vars);
bool	valid_args(int ac, char **av, t_fractal *v);
void	vars_init(t_fractal *vars);
void	ft_putstr(char *s);
void	f_mandelbrot(int x, int y, t_fractal *vars);
void	f_julia(int x, int y, t_fractal *vars);
void	f_burning_ship(int x, int y, t_fractal *vars);
void	my_pixel_put(int x, int y, t_fractal *vars);
double	scale(double n1, double n2, double o, double i);
double	atod(char *s);

#endif
