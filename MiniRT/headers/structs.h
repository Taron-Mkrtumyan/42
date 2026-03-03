/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:29 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/01 16:25:43 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "includes.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_amb_light
{
	double	ratio;
	t_rgb	color;
}	t_amb_light;

typedef struct s_light
{
	double			brightness;
	t_vec			position;
	t_rgb			color;
	struct s_light	*next;
	struct s_light	*first;
}	t_light;

typedef struct s_camera
{
	t_vec	position;
	t_vec	orientation;
	double	fov;
	bool	exists;
}	t_camera;

typedef enum e_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
}	t_shape;

typedef struct s_obj
{
	t_shape			shape;
	void			*data;
	double			shininess;
	struct s_obj	*next;
}	t_obj;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_sphere
{
	double		radius;
	double		diameter;
	t_vec		center;
	t_rgb		color;
}	t_sphere;

typedef struct s_cylinder
{
	double		radius;
	double		diameter;
	double		height;
	t_vec		center;
	t_vec		normal;
	t_rgb		color;
}	t_cylinder;

typedef struct s_plane
{
	t_vec	center;
	t_vec	normal;
	t_rgb	color;
}	t_plane;

typedef struct s_window		t_window;

typedef struct s_minirt
{
	t_window	*window;
	t_camera	*camera;
	t_light		*light;
	t_obj		*objects;
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
	double		width;
	double		height;
	t_minirt	*minirt;
}	t_window;

#endif
