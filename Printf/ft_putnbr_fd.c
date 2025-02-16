/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:24:21 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 18:29:14 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	res;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		res = ft_putnbr_fd(-n, fd);
		if (res == -1)
			return (-1);
		return (1 + res);
	}
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	count = ft_putnbr_fd(n / 10, fd);
	if (count == -1)
		return (-1);
	res = ft_putnbr_fd(n % 10, fd);
	if (res == -1)
		return (-1);
	return (count + res);
}
