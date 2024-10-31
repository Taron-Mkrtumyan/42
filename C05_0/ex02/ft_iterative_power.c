/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:27:47 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/31 12:41:32 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (nb == 1 || nb == 0)
		return (nb);
	res = 1;
	while (power--)
		res *= nb;
	return (res);
}
/*
int	main(void)
{
	printf("%d", ft_iterative_power(9, -1));
}*/
