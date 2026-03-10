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
# include "color_escape_codes.h"
# include "vector_operations1.h"
# include "vector_operations2.h"
# include "color_operations.h"

# define WIDTH		1920
# define HEIGHT		1080

# define SHININESS	100

# define NP_PLUS	65451
# define NP_MINUS	65453

# define EPSILON 1e-6

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

bool			valid_args(t_minirt *rt, char *path, int ac);
bool			is_valid_file(t_minirt *rt);

void			init_window(t_window *w);
bool			init_viewport(t_minirt *rt);
bool			render_scene(t_minirt *minirt);

bool			parse_params(t_minirt *rt, char *line);
bool			parse_vector(char *str, t_vec *vec);
bool			parse_color(char *str, t_rgbd *color);
bool			parse_double(char *str, double *num);
bool			parse_shape(t_minirt *rt, char *line, t_shape type, \
int nb_params);
bool			parse_light(t_minirt *rt, char *line);
bool			parse_ambient(t_minirt *rt, char *line);
bool			parse_resolution(t_minirt *rt, char *line);
bool			parse_camera(t_minirt *rt, char *line);
bool			parse_plane(char **params, t_obj *obj, int file_line);
bool			parse_sphere(char **params, t_obj *obj, int file_line);
bool			parse_cylinder(char **params, t_obj *obj, int file_line);
bool			parse_error_ptr(char *msg, void *ptr, char **params, \
int file_line);
bool			parse_error(char *msg, char **params, int file_line);

void			push_object(t_obj *obj, t_obj **objs);
void			push_light(t_light *new_light, t_light **lights);
t_light			*create_light(t_minirt *rt);

void			free_minirt(t_minirt *minirt);
void			free_window(t_window *w);
void			free_arr(char *arr[]);

char			*get_next_line(int fd);

int				double_length(double num);
int				str_to_int_color(char *str);
bool			is_double(char *str);
bool			is_uchar(char *str);
bool			is_valid_obj_name(char *line);
void			print_minirt(t_minirt *rt);
double			get_shininess(const t_obj *obj);
t_rgbd			get_color(const t_obj *obj);
t_rgb			get_pixel_color(t_minirt *rt, t_obj_hit obj_hit, t_vec ray_dir);
t_vec			get_surface_normal(t_obj *obj, t_vec hit_point);
t_obj_hit		get_obj_hit(t_ray ray, t_obj *objs);
t_hit_surface	get_hit_surface(t_cylinder *cylinder, t_vec hit_point);
bool			does_intersect(t_ray ray, t_obj *obj, t_obj_hit *hit);

t_vec			normalize(t_vec v);
bool			error_msg(char *msg);

#endif
