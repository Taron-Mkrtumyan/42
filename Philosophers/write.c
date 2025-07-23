/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:47:23 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/17 17:58:35 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	write_status(t_philo_status state, t_philo *philo)
{
	long long	current_time;

	mutex_op(&philo->data->write_mutex, LOCK);
	current_time = ft_get_time(MILISECOND) - philo->data->start_time;
	if (state == EATING && !sim_ended(philo->data))
		printf(BW"%lld"BM"\t%d is eating\t\t😋\n"RE, current_time, philo->id);
	else if (state == TOOK && !sim_ended(philo->data))
		printf(BW"%lld\t%d has taken a fork\t🍴\n"RE, current_time, philo->id);
	else if (state == THINKING && !sim_ended(philo->data))
		printf(BW"%lld"Y"\t%d is thinking\t\t🤔\n"RE, current_time, philo->id);
	else if (state == SLEEPING && !sim_ended(philo->data))
		printf(BW"%lld"Y"\t%d is sleeping\t\t😴\n"RE, current_time, philo->id);
	else if (state == DIED)
		printf(BW"%lld"Y"\t%d died\t\t\t💀\n"RE, current_time, philo->id);
	mutex_op(&philo->data->write_mutex, UNLOCK);
}
