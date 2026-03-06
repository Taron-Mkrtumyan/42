/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:32:39 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/03 15:01:24 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_minirt	*minirt;

	minirt = ft_calloc(sizeof(t_minirt), 1);
	if (!minirt)
		return (error_msg("Failed to allocate memory for minirt"), 1);
	minirt->window = ft_calloc(sizeof(t_window), 1);
	if (!minirt->window)
		return (false);
	minirt->window->minirt = minirt;
	minirt->window->width = WIDTH;
	minirt->window->height = HEIGHT;
	if (!valid_args(minirt, av[1], ac))
	{
		free_minirt(minirt);
		return (1);
	}
	init_window(minirt->window);
	free_minirt(minirt);
	return (0);
}

// print_minirt(minirt);
//printf("%f\n", DBL_MAX);
