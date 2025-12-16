/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:37:40 by gkankia           #+#    #+#             */
/*   Updated: 2025/01/26 15:01:09 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*create_str(int i, int sign, int i_copy)
{
	char	*res;

	res = (char *)malloc((i + sign + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i + sign] = '\0';
	while (i > 0)
	{
		res[i + sign - 1] = (i_copy % 10) + '0';
		i_copy = i_copy / 10;
		if (i_copy == 0)
			break ;
		i--;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	int		i_copy;

	sign = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	i_copy = n;
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (create_str(i, sign, i_copy));
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-2147483647));
	return (0);
}*/
