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
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft/libft.h"
# include "minirt.h"
# include "get_next_line.h"
# include <fcntl.h>

# define SIZE		2000
# define QUALITY	0
# define SMOOTH		0.2

# define NP_PLUS	65451
# define NP_MINUS	65453

typedef struct a_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct a_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct a_amb_light
{
	float	ratio;
	t_rgb	color;
}	t_amb_light;

typedef struct a_light
{
	t_vector		position;
	float			brightness;
	t_rgb			color;
	struct a_light	*next;
}	t_light;

typedef struct a_camera
{
	t_vector	position;
	t_vector	orientation;
	float		fov;
	int			is_exist;
}	t_camera;

typedef enum e_shape
{
	SPHERE,
	CYLINDER,
	PLANE,
}	t_shape;

typedef struct a_obj
{
	t_shape			shape;
	void			*data;
	struct a_obj	*next;
}	t_obj;

typedef struct a_sphere
{
	float		radius;
	float		diameter;
	t_vector	center;
	t_rgb		color;
}	t_sphere;

typedef struct a_cylinder
{
	float		radius;
	float		diameter;
	float		height;
	t_vector	center;
	t_vector	normal;
	t_rgb		color;
}	t_cylinder;

typedef struct a_plane
{
	t_vector	center;
	t_vector	normal;
	t_rgb		color;
}	t_plane;

typedef struct s_window	t_window;

typedef struct a_minirt
{
	t_window	*window;
	t_camera	*camera;
	t_light		*light;
	t_obj		*objects;
	t_amb_light	*amb_light;
}	t_minirt;

struct s_window
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	float		width;
	float		height;
	t_minirt	*minirt;
};

void		init_window(t_window *w);
bool		init_minirt(t_minirt *minirt, char *filename);
bool		valid_args(t_minirt *minirt, char *path);
bool		init_scene(t_minirt *minirt, char *filename);
bool		render_scene(t_minirt *minirt);
bool		parse_params(t_minirt *rt, char *line);
bool		parse_resolution(t_minirt *rt, char *line);
int			read_file(t_minirt *rt, int fd);
int			str_to_int(char *str);
float		str_to_float(char *str);
int			is_float(char *str);
int			array_length(char *arr[]);
void		free_array(char *arr[]);
int			parse_vector(char *str, t_vector *vect);
int			parse_color(char *str, t_rgb *color);
int			parse_camera(t_minirt *rt, char *line);
int			parse_ulong(char *str, size_t *num);
int			parse_float(char *str, float *num);
int			is_ulong(char *str);
int			str_to_int_color(char *str);
float		vectlen(t_vector v);
t_vector	*normalize(t_vector *v);
int			parse_ambient(t_minirt *rt, char *line);
t_light		*create_light(t_minirt *rt);
int			parse_light(t_minirt *rt, char *line);
int			parse_sphere(char **params, t_obj *obj);
int			parse_plane(char **params, t_obj *obj);
int			parse_cylinder(char **params, t_obj *obj);
void		push_light(t_light *new_light, t_light **lights);
void		push_object(t_obj *obj, t_obj **objs);
int			parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params);
int			error_msg(char *msg);
int			parse_error(char *msg, char **params);
int			parse_error_ptr(char *msg, void *ptr, char **params);
void		free_minirt(t_minirt *rt);
void		free_window(t_window *win);
void		free_objects(t_obj *obj);
void		free_lights(t_light *light);
t_vector	vect_add(t_vector v1, t_vector v2);
t_vector	vect_sub(t_vector v1, t_vector v2);
t_vector	vect_multi(t_vector v, float f);
void		print_minirt(t_minirt *rt);
int			parse_normal(char *str, t_vector *normal);
#endif
