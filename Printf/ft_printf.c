/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:05:50 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 19:12:51 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_put_u_fd(va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_puthex_low_fd(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_puthex_up_fd(va_arg(args, unsigned int), 1));
	else if (c == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		count;
	int		res;

	va_start (args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			res = put(s[i + 1], args);
			if (res == -1)
				return (-1);
			else
				count += res;
			i += 2;
		}
		else
			count += ft_putchar_fd(s[i++], 1);
	}
	va_end (args);
	return (count);
}
