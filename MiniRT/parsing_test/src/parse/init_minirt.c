/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minirt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:12 by gkankia           #+#    #+#             */
/*   Updated: 2025/12/18 19:03:16 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_minirt(t_minirt *minirt, char *filename)
{
    if (!minirt->window)
        return (false);
    if (!init_scene(minirt, filename))
        return (false);
    init_window(minirt->window);
    if (!render_scene(minirt))
        return (false);
    return (true);
}