/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:40:59 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/30 13:17:16 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	int		k;
	char	c;
	char	num[20];
	int		i;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = 0 - nb;
	}
	if (nb == 0)
		write(1, "0", 1);
	i = 0;
	while (nb > 0)
	{
		k = nb % 10;
		num[i] = k + '0';
		i++;
		nb /= 10;
	}
	while (--i >= 0)
		write(1, &num[i], 1);
}
/*
int main(){
	int n = -214733647;
	ft_putnbr(n);
	return 0;
}*/
