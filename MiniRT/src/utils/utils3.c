/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:54 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:55 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	push_light(t_light *new_light, t_light **lights)
{
	t_light	*tmp;

	if (!(*lights))
		*lights = new_light;
	else
	{
		tmp = *lights;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_light;
	}
}

t_light	*create_light(t_minirt *minirt)
{
	t_light	*new_light;

	new_light = ft_calloc(sizeof(t_light), 1);
	if (!new_light)
		return (0);
	push_light(new_light, &minirt->light);
	return (new_light);
}

void	push_object(t_obj *obj, t_obj **objs)
{
	t_obj	*tmp;

	if (!(*objs))
		*objs = obj;
	else
	{
		tmp = *objs;
		write(2, "{5}\n", 4);
		while (tmp->next)
			tmp = tmp->next;
	write(2, "{6}\n", 4);
		tmp->next = obj;
	}
}
