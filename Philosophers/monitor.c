/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:32:20 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/20 21:34:19 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

static bool	philo_died(t_philo *philo)
{
	if ((unsigned int)ft_get_time(MILISECOND) - get_uint(&philo->philo_mutex,
			&philo->last_meal_time) > philo->data->die_time / 1000)
	{
		return (true);
	}
	return (false);
}

void	*monitor_dinner_full(void *info)
{
	t_data			*data;
	unsigned int	i;

	data = (t_data *)info;
	while (!all_threads_running(&data->data_mutex, &data->threads_running_num,
			data->phil_num))
		;
	while (!sim_ended(data))
	{
		i = 0;
		while (i < data->phil_num || sim_ended(data))
		{
			if (data->philos[i].meals_eaten < (int)data->no_spaghetti)
				break ;
			i++;
		}
		if (i == data->phil_num && !sim_ended(data))
		{
			set_res(data, SUCCESS);
			ft_sleep(10000, data);
			printf(BG"🎉\tNO SPAGETTI LEFT !!\t🎉\n"RE);
		}
	}
	return (NULL);
}

void	*monitor_dinner_die(void *info)
{
	t_data			*data;
	unsigned int	i;

	data = (t_data *)info;
	while (!all_threads_running(&data->data_mutex, &data->threads_running_num,
			data->phil_num))
		;
	while (!sim_ended(data))
	{
		i = 0;
		while (i < data->phil_num && !sim_ended(data))
		{
			if (philo_died(data->philos + i))
			{
				set_res(data, FAIL);
				ft_sleep(1000, data);
				write_status(DIED, data->philos + i);
			}
			i++;
		}
	}
	return (NULL);
}
