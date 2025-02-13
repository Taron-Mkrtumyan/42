/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:40:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:55 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	addr = (unsigned long long)ptr;
	count += write(fd, "0x", 2);
	count += ft_puthex_low_fd(addr, fd);
	return (count);
}
