/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:44:59 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/03 15:47:46 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	special_cases(int nb, int fd)
{
	if (nb == 0)
		write (fd, "0", 1);
	else
		write (fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		k;
	char	num[20];
	int		i;

	if (n == -2147483648 || n == 0)
	{
		special_cases(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		k = n % 10;
		num[i] = (char)(k + '0');
		i++;
		n /= 10;
	}
	while (--i >= 0)
		write(fd, &num[i], 1);
}
