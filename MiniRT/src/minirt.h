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

typedef struct a_window		t_window;
typedef struct a_vector		t_vector;
typedef struct a_RGB		t_RGB;
typedef struct a_obj		t_obj;
typedef struct a_sphere		t_sphere;
typedef struct a_cylinder	t_cylinder;
typedef struct a_plane		t_plane;

typedef struct a_amb_light
{
	float		ratio;
	t_RGB		color;
}	t_amb_light;

typedef struct a_lights
{
	t_vector	position;
	float		brightness;
	t_RGB		color;
}	t_lights;

typedef struct a_camera
{
	t_vector	position;
	t_vector	orientation;
	float		fov;
}	t_camera;

typedef struct a_minirt
{
	t_window	*window;
	t_camera	*cameras;
	t_lights	*lights;
	t_obj		**objects;
	t_amb_light	*amb_light;
}	t_minirt;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_window;

typedef enum e_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
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

#endif
