/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:44:02 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/01 15:54:39 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_normalize(t_vec v)
{
	double		len;

	len = vec_len(v);
	if (len < VEC_EPSILON)
		return ((t_vec){0.0, 0.0, 0.0});
	return (vec_multi(v, 1.0 / len));
}
