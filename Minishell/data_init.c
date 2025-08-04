/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:36:45 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/08/04 13:12:25 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	data_init(t_data *data, int ac, char **av, char **env)
{
	if (ac != 1 && ac != 3)
		ft_exit(BR"Usage:\t./minishell\tOR\t./minishell -c \"command\"\n"RE);
	if (ac == 3 && ft_strncmp("-c", av[1], 2) != 0)
		ft_exit(BR"Interactive mode:\t./minishell -c \"command\"\n"RE);
	data = malloc(sizeof(t_data));
	if (!data)
		ft_exit("Data malloc failed ⛔");
	data->env = env;
	if (ac == 1)
		data->interactive = false;
	else if (ac == 3)
		data->interactive = true;
	return (true);
}
