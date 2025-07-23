/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:48:48 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/10 18:52:37 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	clean_all(t_data *data)
{
	unsigned int	i;

	ft_sleep((data->die_time + data-> eat_time + data->sleep_time), data);
	i = 0;
	while (i < data->phil_num)
	{
		mutex_op(&data->forks[i].fork, DESTROY);
		mutex_op(&data->philos[i].philo_mutex, DESTROY);
		i++;
	}
	mutex_op(&data->data_mutex, DESTROY);
	mutex_op(&data->write_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
	free(data);
	data = NULL;
}
