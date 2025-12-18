/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:32:39 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/12/16 19:55:52 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_minirt	minirt;
	t_window		window;	

	if (!valid_args(ac, av))
		return (1);
	if (!init_minirt(&minirt, av[1]))
		return (2);
	return (0);
}
