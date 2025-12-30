/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:35:51 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/12/18 17:39:35 by gkankia          ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"
# include <string.h>
# include <math.h>
# include <stdlib.h>

# define SIZE		2000
# define QUALITY	0
# define SMOOTH		0.2

# define NP_PLUS	65451
# define NP_MINUS	65453

typedef struct s_window		t_window;
typedef struct s_vector		t_vector;
typedef struct s_rgb		t_rgb;
typedef struct s_obj		t_obj;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_plane		t_plane;

typedef struct s_amb_light
{
	float		ratio;
	t_rgb		*color;
}	t_amb_light;

typedef struct s_light
{
	t_vector	*position;
	t_rgb		*color;
	float		brightness;
}	t_light;

typedef struct s_camera
{
	t_vector	*position;
	t_vector	*orientation;
	float		fov;
}	t_camera;

typedef struct s_minirt
{
	t_window	*window;
	t_camera	*camera;
	t_light		*light;
	t_obj		**objects;
	t_amb_light	*amb_light;
}	t_minirt;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	t_minirt	*minirt;
}	t_window;

typedef enum e_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
}	t_shape;

typedef struct s_obj
{
	t_shape	shape;
	void	*data;	
}	t_obj;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_sphere
{
	float		radius;
	float		diameter;
	t_vector	*center;
	t_rgb		*color;
}	t_sphere;

typedef struct s_cylinder
{
	float		radius;
	float		diameter;
	float		height;
	t_vector	*center;
	t_vector	*normal;
	t_rgb		*color;
}	t_cylinder;

typedef struct s_plane
{
	t_vector	*center;
	t_vector	*normal;
	t_rgb		*color;
}	t_plane;

void	init_window(t_window *w);
bool	init_minirt(t_minirt *minirt, char *filename);
bool	valid_args(int ac, char **av);
bool	init_scene(t_minirt *minirt, char *filename);
bool	render_scene(t_minirt *minirt);

#endif
