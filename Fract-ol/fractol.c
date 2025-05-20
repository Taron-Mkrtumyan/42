/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:09:35 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/20 18:31:18 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char	**av)
{
	t_fractal	vars;

	if (!valid_args(ac, av, &vars))
	{
		ft_putstr(INVALID_INPUT);
		return (1);
	}
	vars_init(&vars);
	return (0);
}
