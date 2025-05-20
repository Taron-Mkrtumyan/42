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

//ESC Space
int	handle_key(int keycode, t_fractal *vars)
{
	if (keycode == 65307)
	{
		printf("The key %d (ESC) was pressed. Exiting.\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == 32)
	{
		printf("Space\n");
	}
	return (0);
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
	//events_init(v)			//TODO
	render_fractal(v);
	mlx_loop(v->mlx);
	mlx_destroy_window(v->mlx, v->win);
	return (mlx_destroy_display(v->mlx), free(v->mlx));
}
