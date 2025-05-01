/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:15:31 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/11/02 14:21:20 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	*ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if(min >= max)
	{
		*range[0] = NULL;
		return (0);
	}
	arr = malloc((max -min) * sizeof(int));
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (max - min);
}

int	main(void)
{
	int	*arr;

	arr = ft_range(-20, 10);
	for (int i = 0; i < 31; i++)
		printf("%d ", arr[i]);
}
