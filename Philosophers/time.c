/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:46:38 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/10 18:47:22 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

long long	ft_get_time(t_time_type time_type)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	if (SECOND == time_type)
		return (time.tv_sec);
	if (MILISECOND == time_type)
		return (time.tv_sec * 1000 + time.tv_usec / 1000);
	if (MICROSECOND == time_type)
		return (time.tv_sec * 1000000 + time.tv_usec);
	return (0);
}

void	ft_sleep(long long usec, t_data *data)
{
	long long	start;
	long long	current;
	long long	remaining;

	start = ft_get_time(MICROSECOND);
	while (1)
	{
		current = ft_get_time(MICROSECOND);
		if (current - start >= usec || sim_ended(data))
			break ;
		remaining = usec - (current - start);
		if (remaining > 1000)
			usleep(remaining / 2);
		else
			usleep(100);
	}
}
