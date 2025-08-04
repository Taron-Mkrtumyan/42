/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:31:39 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/30 13:18:13 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (!data_init(&data, ac, av, envp))
		return (1);
	clean_all(&data);
	return (0);
}
