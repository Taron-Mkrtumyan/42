/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:56:36 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 15:39:23 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u_fd(unsigned int n, int fd)
{
	int	count;
	int	res;

	count = 0;
	if (n >= 10)
	{
		res = ft_put_u_fd(n / 10, fd);
		if (res == -1)
			return (-1);
		count += res;
	}
	res = ft_putchar_fd((n % 10) + '0', fd);
	if (res == -1)
		return (-1);
	count += res;
	return (count);
}
