/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:35:51 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/12/18 17:27:35 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
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

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	a_camera	*camera;
	a_light		*light;
	a_amb_light	*amb_light;
}	t_window;

typedef enum e_shape
{
	SPHERE;
	CYLINDER;
	PLANE;
}	t_shape;

typedef struct a_obj
{
	t_shape	shape;
	void	*data;	
}	t_obj;

typedef struct a_RGB
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_RGB;

typedef struct a_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct a_sphere
{
	float		radius;
	float		diameter;
	t_vector	center;
	t_RGB		color;
}	t_sphere;

typedef struct a_cylinder
{
	float		radius;
	float		diameter;
	float		height;
	t_vector	center;
	t_vector	normal;
	t_RGB		color;
}	t_cylinder;

typedef struct a_plane
{
	t_vector	center;
	t_vector	normal;
	t_RGB		color;
}	t_plane;

void	render_fractal(t_fractal *vars);
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
