/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:23:29 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 20:35:27 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "includes.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_quadratic_eq
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
}				t_quadratic_eq;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;

typedef struct s_rgbd
{
	double	r;
	double	g;
	double	b;
}				t_rgbd;

typedef struct s_amb_light
{
	double	ratio;
	t_rgbd	color;
}				t_amb_light;

typedef struct s_light
{
	double			brightness;
	t_vec			position;
	t_rgbd			color;
	struct s_light	*next;
	struct s_light	*first;
}					t_light;

typedef struct s_camera
{
	t_vec	position;
	t_vec	orientation;
	double	fov;
	bool	exists;
}				t_camera;

typedef enum e_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
}			t_shape;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}						t_ray;

typedef enum e_hit_surface
{
	HIT_SIDE,
	HIT_TOP,
	HIT_BOTTOM,
	NO_HIT
}			t_hit_surface;

typedef struct s_lightings
{
	t_rgbd	ambient;
	t_rgbd	diffuse;
	t_rgbd	specular;
}						t_lightings;

typedef struct s_obj
{
	t_shape			shape;
	void			*data;
	struct s_obj	*next;
}						t_obj;

typedef struct s_sphere
{
	double		radius;
	double		diameter;
	double		shininess;
	t_vec		center;
	t_rgbd		color;
}						t_sphere;

typedef struct s_cylinder
{
	double			radius;
	double			diameter;
	double			shininess;
	double			height;
	double			half;
	double			cap_t;
	t_vec			top_center;
	t_vec			bottom_center;
	t_vec			center;
	t_vec			normal;
	t_rgbd			color;
	t_hit_surface	hit_surface;
}						t_cylinder;

typedef struct s_plane
{
	double		shininess;
	t_vec		center;
	t_vec		normal;
	t_rgbd		color;
}						t_plane;

typedef struct s_viewport
{
	t_vec		normal;
	t_vec		right;
	t_vec		up;
	double		width;
	double		height;
}						t_viewport;

typedef struct s_obj_hit
{
	t_vec		hit_point;
	t_vec		normal;
	t_obj		*obj;
	double		t;
}						t_obj_hit;

typedef struct s_window		t_window;

typedef struct s_minirt
{
	t_window		*window;
	t_camera		*camera;
	t_light			*lights;
	t_obj			*objects;
	t_amb_light		*amb_light;
	t_viewport		*viewport;
	int				file_line;
}							t_minirt;

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
}						t_window;

#endif
