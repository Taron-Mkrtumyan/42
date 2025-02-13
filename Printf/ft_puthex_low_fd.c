/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:32:23 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 18:28:12 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low_fd(unsigned long long n, int fd)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_low_fd(n / 16, fd);
	if ((n % 16) < 10)
		count += ft_putchar_fd((n % 16) + '0', fd);
	else
		count += ft_putchar_fd((n % 16) - 10 + 'a', fd);
	return (count);
}
