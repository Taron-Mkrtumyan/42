/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:21:35 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/01/30 12:42:46 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(int n)
{
	int	ctr;

	if (n == 0)
		return (1);
	ctr = 0;
	while (n != 0)
	{
		ctr++;
		n /= 10;
	}
	return (ctr);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		n_len;

	n_len = num_len(n);
	res = (char *)malloc((n_len + 1 + (n < 0)) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[n_len + (n < 0)] = '\0';
	while (n_len--)
	{
		res[n_len + (n < 0)] = (char)(ft_abs (n % 10) + '0');
		n /= 10;
	}
	return (res);
}
