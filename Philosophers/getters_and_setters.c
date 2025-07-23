/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_and_setters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:21:57 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/14 22:29:50 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	mutex_op(mutex, LOCK);
	*dest = value;
	mutex_op(mutex, UNLOCK);
}

bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	res;

	mutex_op(mutex, LOCK);
	res = *value;
	mutex_op(mutex, UNLOCK);
	return (res);
}

unsigned int	get_uint(t_mtx *mutex, unsigned int *value)
{
	unsigned int	res;

	mutex_op(mutex, LOCK);
	res = *value;
	mutex_op(mutex, UNLOCK);
	return (res);
}

void	set_uint(t_mtx *mutex, unsigned int *dest, unsigned int value)
{
	mutex_op(mutex, LOCK);
	*dest = value;
	mutex_op(mutex, UNLOCK);
}
