/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:20:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/14 18:22:24 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	thread_op(pthread_t *thread, void *data, t_action action,
			void *(*function)(void *))
{
	if (action == CREATE)
		pthread_create(thread, NULL, function, data);
	else if (action == JOIN)
		pthread_join(*thread, NULL);
	else if (action == DETACH)
		pthread_detach(*thread);
}
