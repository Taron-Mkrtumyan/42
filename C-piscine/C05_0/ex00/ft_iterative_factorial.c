/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:46:21 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/30 18:55:32 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	res = 1;
	while (nb)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
/*
int	main(void)
{
	printf("%d\n", ft_iterative_factorial(2));
}*/
