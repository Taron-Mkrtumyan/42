/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:24:13 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/30 16:40:05 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits_len(int size)
{
	int	bits;

	bits = 0;
	while (size > 0)
	{
		bits++;
		size /= 2;
	}
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	bits;
	int	size;

	i = 0;
	size = stack_len(*a);
	bits = max_bits_len(size - 1);
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
