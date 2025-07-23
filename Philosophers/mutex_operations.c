/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:47:22 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/14 17:51:19 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

bool	mutex_op(t_mtx *mutex, t_action action)
{
	if (action == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (false);
		return (true);
	}
	else if (action == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (false);
		return (true);
	}
	else if (action == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (false);
		return (true);
	}
	else if (action == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (false);
		return (true);
	}
	return (false);
}
