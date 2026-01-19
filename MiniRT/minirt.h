/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:35:51 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 17:45:10 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define SIZE		1000
# define QUALITY	0
# define SMOOTH		0.2

# define NP_PLUS	65451
# define NP_MINUS	65453

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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
	float			brightness;
	t_vector		*position;
	t_rgb			*color;
	struct s_light	*next;
	struct s_light	*first;
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
	t_light		**lights;
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
	float		width;
	float		height;
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
	t_shape			shape;
	void			*data;
	struct s_obj	*next;
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

void		init_window(t_window *w);
bool		init_minirt(t_minirt *minirt, char *filename);
bool		valid_args(t_minirt *rt, char *path);
bool		init_scene(t_minirt *minirt, char *filename);
bool		render_scene(t_minirt *minirt);
void		free_minirt(t_minirt *minirt);
void		free_window(t_window *w);
void		free_arr(char *arr[]);
bool		parse_params(t_minirt *rt, char *line);
int			is_invalid_file(t_minirt *rt);
t_vector	*normalize(t_vector *v);
void		push_light(t_light *new_light, t_light **lights);
t_light		*create_light(t_minirt *rt);
void		push_object(t_obj *obj, t_obj **objs);
int			is_ulong(char *str);
float		str_to_float(char *str);
int			is_float(char *str);
int			arr_len(char *arr[]);
int			str_to_int_color(char *str);
int			parse_vector(char *str, t_vector *vec);
int			parse_colors(char *str, t_rgb *color, t_rgb *color2);
int			parse_color(char *str, t_rgb *color);
int			parse_float(char *str, float *num);
float		vec_len(t_vector *vec);
char		*sub(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
int			parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params);
int			parse_light(t_minirt *rt, char *line);
int			parse_ambient(t_minirt *rt, char *line);
bool		parse_resolution(t_minirt *rt, char *line);
int			parse_camera(t_minirt *rt, char *line, int i);
int			parse_plane(char **params, t_obj *obj);
int			parse_sphere(char **params, t_obj *obj);
int			parse_cylinder(char **params, t_obj *obj);

#endif
