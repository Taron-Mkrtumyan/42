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

static	inline t_rgb	color_add(t_rgb c1, t_rgb c2)
{
	return ((t_rgb){c1.r + c2.r, c1.g + c2.g, c1.b + c2.b});
}

static	inline t_rgb	color_multi(t_rgb c, double factor)
{
	return ((t_rgb){(unsigned char)(c.r * factor), \
(unsigned char)(c.g * factor), (unsigned char)(c.b * factor)});
}

#endif
