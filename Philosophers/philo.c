/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:37:23 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/09 21:35:45 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

static void	print_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (!valid_args(ac, av))
	{
		printf("\n\t❌\t");
		print_args(av);
		usleep(500000);
		printf(BR"\t\t\tWRONG INPUT\n\n"RE);
		usleep(500000);
		printf("\t✅\n");
		usleep(500000);
		printf(BG"\t\t./philo 5 800 200 200 [7]\n\n"RE);
		usleep(500000);
		return (1);
	}
	data = NULL;
	data = data_init(data, av);
	if (!data)
		return (clean_all(data), 2);
	simulate (data);
	usleep(1000);
	clean_all (data);
	return (0);
}
