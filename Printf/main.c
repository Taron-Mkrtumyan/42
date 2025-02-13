/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:03:05 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 18:41:31 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	char			c;
	char			*s;
	int				n;
	unsigned int	k;
	unsigned int	x;

	c = 'c';
	s = "string";
	n = -42;
	k = 42;
	x = 42;
	printf("%d\n\n", ft_printf("Test\n%c\n%s\n%d\n%u\n%x\n\n", c, s, n, k, x));
	printf("%d\n\n ", printf("Test\n%c\n%s\n%d\n%u\n%x\n\n", c, s, n, k, x));
	printf("%d\n", printf("\001\002\007\v\010\f\r\n"));
	printf("%d\n", ft_printf("\001\002\007\v\010\f\r\n"));
	return (0);
}
	/* ft_puthex_up_fd(255, 1);  // Should print: FF
	write(1, "\n", 1);
	ft_puthex_up_fd(16, 1);   // Should print: 10
	write(1, "\n", 1);
	ft_puthex_up_fd(42, 1);   // Should print: 2A
	write(1, "\n", 1);
	ft_puthex_low_fd(255, 1);  // Should print: ff 
	write(1, "\n", 1);
	ft_puthex_low_fd(16, 1);   // Should print: 10
	write(1, "\n", 1);
	ft_puthex_low_fd(42, 1);   // Should print: 2a
	write(1, "\n", 1);
	return (0);*/
