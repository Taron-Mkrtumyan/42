/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:15:33 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/14 17:16:08 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

static bool	init_forks(t_data *data)
{
	unsigned int	i;

	data->forks = malloc(sizeof(t_fork) * data->phil_num);
	if (!data->forks)
		return (false);
	i = 0;
	while (i < data->phil_num)
	{
		mutex_op(&data->forks[i].fork, INIT);
		data->forks[i].fid = i;
		i++;
	}
	return (true);
}

static void	assign_forks(t_philo *philo, t_fork *forks, unsigned int i)
{
	if (philo->id % 2 == 0)
	{
		philo->second_fork = &forks[(i + 1) % philo->data->phil_num];
		philo->first_fork = &forks[i];
	}
	else
	{
		philo->first_fork = &forks[(i + 1) % philo->data->phil_num];
		philo->second_fork = &forks[i];
	}
}

static bool	init_philos(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	philo = NULL;
	data->philos = malloc(sizeof(t_philo) * data->phil_num);
	if (!data->philos)
		return (false);
	while (i < data->phil_num)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->data = data;
		philo->meals_eaten = 0;
		memset(&philo->tid, 0, sizeof(pthread_t));
		mutex_op(&philo->philo_mutex, INIT);
		assign_forks(philo, data->forks, i);
		i++;
	}
	return (true);
}

static void	init_args(t_data *data, char **av)
{
	data->phil_num = ft_atoi(av[1]);
	data->die_time = (long long)(ft_atoi(av[2]) * 1000);
	data->eat_time = (long long)(ft_atoi(av[3]) * 1000);
	data->sleep_time = (long long)(ft_atoi(av[4]) * 1000);
}

t_data	*data_init(t_data *data, char **av)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_args(data, av);
	data->start_time = ft_get_time(MILISECOND);
	data->all_threads_ready = false;
	data->threads_running_num = 0;
	data->end = UNKNOWN;
	memset(&data->monitor_die, 0, sizeof(pthread_t));
	memset(&data->monitor_full, 0, sizeof(pthread_t));
	if (mutex_op(&data->data_mutex, INIT) == false)
		return (NULL);
	if (mutex_op(&data->write_mutex, INIT) == false)
		return (NULL);
	data->no_spaghetti = 0;
	if (av[5])
		data->no_spaghetti = ft_atoi(av[5]);
	if (!init_forks(data))
		return (NULL);
	if (!init_philos(data))
		return (NULL);
	return (data);
}
