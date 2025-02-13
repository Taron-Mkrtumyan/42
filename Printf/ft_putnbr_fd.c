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

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		return (1 + ft_putnbr_fd(-n, fd));
	}
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	count = ft_putnbr_fd(n / 10, fd);
	return (count + ft_putnbr_fd(n % 10, fd));
}
