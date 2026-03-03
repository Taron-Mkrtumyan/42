/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:01:05 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/01 16:03:36 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_OPERATIONS_H
# define COLOR_OPERATIONS_H

# include "structs.h"

static inline t_rgbd	to_rgbd(t_rgb c)
{
	return ((t_rgbd){(double)c.r / 255, (double)c.g / 255, (double)c.b / 255});
}

static inline t_rgb	to_rgb(t_rgbd c)
{
	return ((t_rgb){(unsigned char)(fmin(1, c.r) * 255), \
(unsigned char)(fmin(1, c.g) * 255), (unsigned char)(fmin(1, c.b) * 255)});
}

static inline t_rgbd	color_add(t_rgbd c1, t_rgbd c2)
{
	return ((t_rgbd){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

static inline t_rgbd	color_multi(t_rgbd c, double factor)
{
	return ((t_rgbd){c.r * factor, c.g * factor, c.b * factor});
}

#endif
