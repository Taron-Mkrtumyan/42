/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:40:59 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/10/30 15:56:45 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	special_cases(int nb)
{
	if (nb == 0)
		write (1, "0", 1);
	else
		write (1, "-2147483648", 11);
}

void	ft_putnbr(int nb)
{
	int		k;
	char	num[20];
	int		i;

	if (nb == -2147483648 || nb == 0)
	{
		special_cases(nb);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
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
	int n = -2147483649;
	ft_putnbr(n);
	return 0;
}*/
