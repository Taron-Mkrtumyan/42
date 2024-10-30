/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:18:39 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/30 13:53:39 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int	ctr;
	int	res;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	ctr = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ctr++;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res + (str[i] - '0')) * 10;
		i++;
	}
	res /= 10;
	if (ctr % 2 == 0)
		return (res);
	return (-res);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi("  -		--+--+123a4567"));
}*/
