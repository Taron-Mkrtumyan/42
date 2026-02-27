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

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>
# include <fcntl.h>
# include <float.h>
# include <math.h>

# define SIZE		1000
# define QUALITY	0
# define SMOOTH		0.2

# define NP_PLUS	65451
# define NP_MINUS	65453

# define VEC_EPSILON 1e-14

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define RED		0xFF0000
# define RESET		0xFFFFFF

# define ERR_MALLOC			"Error\nMemory allocation failed\n"
# define ERR_ARGS			"Error\nWrong number of arguments\n"
# define ERR_MAP			"Error\nBad formatting of the map_file\n"
# define ERR_READING		"Error\nCannot read the map_file\n"
# define ERR_FD_OPEN		"Error\nCould not open the map_file\n"
# define ERR_FD_CLOSE		"Error\nCould not close the map_file\n"
# define ERR_IS_DIR			"Error\nThe file is a directory, not a map\n"
# define ERR_MLX			"Error\nMLX initiation failed\n"
# define ERR_WIN			"Error\nWindow initiation failed\n"
# define ERR_IMG			"Error\nError on image initiation\n"

#define SUCCES 0
#define ERROR_FILE_OPEN 1

#define ERROR_MALLOC_LINE 2
#define ERROR_MALLOC_AMBIENT 3
#define ERROR_MALLOC_CAMERA 4
#define ERROR_MALLOC_CAMERA_ORIGIN 5
#define ERROR_MALLOC_CAMERA_DIRECTION 6
#define ERROR_MALLOC_LIGHT 7
#define ERROR_MALLOC_LIGHT_ORIGIN 8
#define ERROR_MALLOC_OBJECTS_LIST 9

#define ERROR_MALLOC "Error\nMemory allocation failed\n"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

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
	t_vector		position;
	t_rgb			color;
	struct s_light	*next;
	struct s_light	*first;
}	t_light;

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	double		fov;
	bool		exists;
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
	struct s_obj	*next;
}	t_obj;

typedef struct s_sphere
{
	double		radius;
	double		diameter;
	t_vector	center;
	t_rgb		color;
}	t_sphere;

typedef struct s_cylinder
{
	double		radius;
	double		diameter;
	double		height;
	t_vector	center;
	t_vector	normal;
	t_rgb		color;
}	t_cylinder;

typedef struct s_plane
{
	t_vector	center;
	t_vector	normal;
	t_rgb		color;
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

bool		valid_args(t_minirt *rt, char *path, int ac);
bool		is_valid_file(t_minirt *rt);

void		init_window(t_window *w);
bool		init_minirt(t_minirt *minirt, char *filename);
bool		init_scene(t_minirt *minirt, char *filename);
bool		render_scene(t_minirt *minirt);

bool		parse_params(t_minirt *rt, char *line);
bool		parse_vector(char *str, t_vector *vec);
bool		parse_color(char *str, t_rgb *color);
bool		parse_double(char *str, double *num);
bool		parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params);
bool		parse_light(t_minirt *rt, char *line);
bool		parse_ambient(t_minirt *rt, char *line);
bool		parse_resolution(t_minirt *rt, char *line);
bool		parse_camera(t_minirt *rt, char *line);
bool		parse_plane(char **params, t_obj *obj);
bool		parse_sphere(char **params, t_obj *obj);
bool		parse_cylinder(char **params, t_obj *obj);
bool		parse_error_ptr(char *msg, void *ptr, char **params);
bool		parse_error(char *msg, char **params);

void		push_object(t_obj *obj, t_obj **objs);
void		push_light(t_light *new_light, t_light **lights);
t_light		*create_light(t_minirt *rt);

void		free_minirt(t_minirt *minirt);
void		free_window(t_window *w);
void		free_arr(char *arr[]);

char		*sub(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);

int			double_length(double num);
bool		is_double(char *str);
bool		is_ulong(char *str);
int			str_to_int_color(char *str);
void		print_minirt(t_minirt *rt);

double		vec_len(const t_vector *vec);
double		vec_dot(const t_vector *v1, const t_vector *v2);
void		vector_normalize(t_vector *v);
t_vector	vector_add(const t_vector *v1, const t_vector *v2);
t_vector	vector_sub(const t_vector *v1, const t_vector *v2);
t_vector	vector_multi(const t_vector *v, double f);

bool		error_msg(char *msg);

#endif
