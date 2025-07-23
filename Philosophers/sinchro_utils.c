/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:12:58 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/17 17:15:18 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_threads_ready))
		;
}

bool	all_threads_running(t_mtx *mutex, long long *threads,
			long long philo_nbr)
{
	bool	res;

	res = false;
	mutex_op(mutex, LOCK);
	if (*threads >= philo_nbr)
		res = true;
	mutex_op(mutex, UNLOCK);
	return (res);
}

void	increase_ctr(t_mtx *mutex, long long *value)
{
	mutex_op(mutex, LOCK);
	(*value)++;
	mutex_op(mutex, UNLOCK);
}

void	de_synchro(t_philo *philo)
{
	if (philo->data->phil_num % 2 == 0)
	{
		if (philo->id % 2 == 0)
			ft_sleep(30000, philo->data);
	}
	else
	{
		if (philo->id % 2)
			think(philo, false);
	}
}
