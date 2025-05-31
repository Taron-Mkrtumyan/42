/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:57:51 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 18:00:11 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_close(t_fractal *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int keycode, t_fractal *vars)
{
	if (keycode == XK_Escape)
		handle_close(vars);
	else if (keycode == XK_space)
		vars->quality += 1;
	else if (keycode == XK_Left || keycode == XK_a)
		vars->shift_x -= SMOOTH * vars->zoom;
	else if (keycode == XK_Right || keycode == XK_d)
		vars->shift_x += SMOOTH * vars->zoom;
	else if (keycode == XK_Up || keycode == XK_w)
		vars->shift_y += SMOOTH * vars->zoom;
	else if (keycode == XK_Down || keycode == XK_s)
		vars->shift_y -= SMOOTH * vars->zoom;
	else if (keycode == NP_PLUS)
		vars->zoom /= 1.1;
	else if (keycode == NP_MINUS)
		vars->zoom *= 1.1;
	else if (keycode == XK_j)
	{
		vars->re = 0.7885 * cos(vars->a);
		vars->im = 0.7885 * sin(vars->a);
		vars->a += 0.01;
	}
	render_fractal(vars);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *vars)
{
	double	prev_zoom;
	double	mouse_re;
	double	mouse_im;

	prev_zoom = vars->zoom;
	mouse_re = scale(-2, 2, SIZE, x) * prev_zoom + vars->shift_x;
	mouse_im = scale(2, -2, SIZE, y) * prev_zoom + vars->shift_y;
	if (button == Button4)
		vars->zoom /= 1.05;
	else if (button == Button5)
		vars->zoom *= 1.05;
	else
		return (0);
	vars->shift_x = mouse_re - scale(-2, 2, SIZE, x) * vars->zoom;
	vars->shift_y = mouse_im - scale(2, -2, SIZE, y) * vars->zoom;
	render_fractal(vars);
	return (0);
}

static void	events_init(t_fractal *vars)
{
	mlx_key_hook(vars->win, handle_key, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, handle_mouse, vars);
	mlx_hook(vars->win, DestroyNotify, StructureNotifyMask, handle_close, vars);
}

void	vars_init(t_fractal *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
		return ;
	v->win = mlx_new_window(v->mlx, SIZE, SIZE, v->name);
	if (!v->win)
		return (mlx_destroy_display(v->mlx), free(v->mlx));
	mlx_key_hook(v->win, handle_key, &v->mlx);
	v->img = mlx_new_image(v->mlx, SIZE, SIZE);
	if (!v->img)
		return (mlx_destroy_window(v->mlx, v->win), \
mlx_destroy_display(v->mlx), free(v->mlx));
	v->addr = mlx_get_data_addr(v->img, &v->bpp, &v->line_len, &v->endian);
	events_init(v);
	render_fractal(v);
	mlx_loop(v->mlx);
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	return (mlx_destroy_display(v->mlx), free(v->mlx));
}
