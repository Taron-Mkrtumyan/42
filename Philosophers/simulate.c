/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:16:23 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/14 17:17:26 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	think(t_philo *philo, bool print)
{
	long long	eat_time;
	long long	sleep_time;
	long long	think_time;

	if (print)
		write_status(THINKING, philo);
	if (philo->data->phil_num % 2 == 0)
		return ;
	eat_time = philo->data->eat_time;
	sleep_time = philo->data->sleep_time;
	think_time = eat_time * 2 - sleep_time;
	if (think_time < 0)
		think_time = 0;
	ft_sleep(think_time / 2, philo->data);
}

static void	*hopeless_sim(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	write_status(THINKING, philo);
	ft_sleep(philo->data->die_time, philo->data);
	philo->data->end = FAIL;
	write_status(DIED, philo);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	mutex_op(&philo->first_fork->fork, LOCK);
	write_status(TOOK, philo);
	mutex_op(&philo->second_fork->fork, LOCK);
	write_status(TOOK, philo);
	set_uint(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILISECOND));
	write_status(EATING, philo);
	ft_sleep(philo->data->eat_time, philo->data);
	philo->meals_eaten++;
	mutex_op(&philo->first_fork->fork, UNLOCK);
	mutex_op(&philo->second_fork->fork, UNLOCK);
}

static void	*dinner_sim(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	wait_all_threads(philo->data);
	set_uint(&philo->philo_mutex, &philo->last_meal_time,
		ft_get_time(MILISECOND));
	increase_ctr(&philo->data->data_mutex, &philo->data->threads_running_num);
	de_synchro(philo);
	while (!sim_ended(philo->data))
	{
		eat(philo);
		write_status(SLEEPING, philo);
		ft_sleep(philo->data->sleep_time, philo->data);
		think(philo, true);
	}
	return (NULL);
}

void	simulate(t_data *data)
{
	int	i;

	if (1 == data->phil_num)
	{
		thread_op(&data->philos[0].tid, &data->philos[0], CREATE, hopeless_sim);
		thread_op (&data->philos[0].tid, NULL, JOIN, NULL);
		return ;
	}
	i = -1;
	while (++i < (int)data->phil_num)
		thread_op(&data->philos[i].tid, &data->philos[i], CREATE, dinner_sim);
	thread_op(&data->monitor_die, data, CREATE, monitor_dinner_die);
	if (data->no_spaghetti > 0)
		thread_op(&data->monitor_full, data, CREATE, monitor_dinner_full);
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	i = -1;
	while (++i < (int)data->phil_num)
		thread_op (&data->philos[i].tid, NULL, JOIN, NULL);
	if (data->no_spaghetti > 0)
		thread_op (&data->monitor_full, NULL, JOIN, NULL);
	thread_op (&data->monitor_die, NULL, JOIN, NULL);
}
