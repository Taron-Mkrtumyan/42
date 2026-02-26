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
	t_minirt	*minirt;

	minirt = ft_calloc(sizeof(t_minirt), 1);
	if (!valid_args(minirt, av[1], ac))
	{
		free_minirt(minirt);
		return (1);
	}
	print_minirt(minirt);
	if (!init_minirt(minirt, av[1]))
		return (2);
	free_minirt(minirt);
	return (0);
}


//printf("%f\n", DBL_MAX);
