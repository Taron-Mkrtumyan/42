/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:35:51 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 17:44:19 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "includes.h"
# include "structs.h" 
# include "vector_operations1.h"
# include "vector_operations2.h"
# include "color_operations.h"

# define WIDTH		1920
# define HEIGHT		1080

# define NP_PLUS	65451
# define NP_MINUS	65453

# define VEC_EPSILON 1e-14

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define GREEN		"\033[32m"
# define RED		"\033[31m"
# define BOLDRED	"\033[1;31m"
# define CYAN		"\033[36m"  
# define BOLDCYAN	"\033[1;36m"
# define RESET		"\033[0m"

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

# define SUCCES 0
# define ERROR_FILE_OPEN 1

# define ERROR_MALLOC_LINE 2
# define ERROR_MALLOC_AMBIENT 3
# define ERROR_MALLOC_CAMERA 4
# define ERROR_MALLOC_CAMERA_ORIGIN 5
# define ERROR_MALLOC_CAMERA_DIRECTION 6
# define ERROR_MALLOC_LIGHT 7
# define ERROR_MALLOC_LIGHT_ORIGIN 8
# define ERROR_MALLOC_OBJECTS_LIST 9

# define ERROR_MALLOC "Error\nMemory allocation failed\n"

bool		valid_args(t_minirt *rt, char *path, int ac);
bool		is_valid_file(t_minirt *rt);

void		init_window(t_window *w);
bool		init_viewport(t_minirt *rt);
bool		render_scene(t_minirt *minirt);

bool		parse_params(t_minirt *rt, char *line);
bool		parse_vector(char *str, t_vec *vec);
bool		parse_color(char *str, t_rgbd *color);
bool		parse_double(char *str, double *num);
bool		parse_shape(t_minirt *rt, char *line, t_shape type, int nb_params);
bool		parse_light(t_minirt *rt, char *line);
bool		parse_ambient(t_minirt *rt, char *line);
bool		parse_resolution(t_minirt *rt, char *line);
bool		parse_camera(t_minirt *rt, char *line);
bool		parse_plane(char **params, t_obj *obj, int file_line);
bool		parse_sphere(char **params, t_obj *obj, int file_line);
bool		parse_cylinder(char **params, t_obj *obj, int file_line);
bool		parse_error_ptr(char *msg, void *ptr, char **params, int file_line);
bool		parse_error(char *msg, char **params, int file_line);

void		push_object(t_obj *obj, t_obj **objs);
void		push_light(t_light *new_light, t_light **lights);
t_light		*create_light(t_minirt *rt);

void		free_minirt(t_minirt *minirt);
void		free_window(t_window *w);
void		free_arr(char *arr[]);

char		*get_next_line(int fd);

int			double_length(double num);
int			str_to_int_color(char *str);
bool		is_double(char *str);
bool		is_uchar(char *str);
bool		is_valid_obj_name(char *line);
void		print_minirt(t_minirt *rt);
double		get_shininess(const t_obj *obj);
t_rgbd		get_color(const t_obj *obj);
t_rgb		get_pixel_color(t_minirt *rt, t_obj *obj, t_vec \
hit_point, t_vec ray);

t_vec		normalize(t_vec v);

bool		error_msg(char *msg);


#endif
