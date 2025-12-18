/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:20:34 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/12/18 19:20:37 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	handle_close(t_window *w)
{
	mlx_destroy_image(w->mlx, w->img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int keycode, t_window *w)
{
	if (keycode == XK_Escape)
		handle_close(w);
	//render_scene(w);
	return (0);
}

static int	handle_mouse(int button, int x, int y, t_window *w);

static void	events_init(t_window *w)
{
	mlx_key_hook(w->win, handle_key, w);
	mlx_hook(w->win, ButtonPress, ButtonPressMask, handle_mouse, w);
	mlx_hook(w->win, DestroyNotify, StructureNotifyMask, handle_close, w);
}

void	init_window(t_window *w)
{
    w = malloc(sizeof(t_window));
    if (!w)
        return ;
    w->mlx = mlx_init();
    if (!w->mlx)
        return (free(w));
    w->win = mlx_new_window(w->mlx, SIZE, SIZE, "MiniRT");
    if (!w->win)
        return (mlx_destroy_display(w->mlx), free(w->mlx));
    mlx_key_hook(w->win, handle_key, &w->mlx);
    w->img = mlx_new_image(w->mlx, SIZE, SIZE);
    if (!w->img)
        return (mlx_destroy_window(w->mlx, w->win), \
                mlx_destroy_display(w->mlx), free(w->mlx));
    w->addr = mlx_get_data_addr(w->img, &w->bpp, &w->line_len, &w->endian);
    events_init(w);
    render_fractal(w);
    mlx_loop(w->mlx);
    mlx_destroy_image(w->mlx, w->img);
    mlx_destroy_window(w->mlx, w->win);
    return (mlx_destroy_display(w->mlx), free(w->mlx));
}


