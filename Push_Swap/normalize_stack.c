/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:58:08 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/30 17:10:20 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_arr(t_stack *a, int *arr)
{
	int	i;

	i = 0;
	while (a)
	{
		arr[i++] = a->data;
		a = a->next;
	}
}

static void	bubble_sort(int *arr, int size)
{
	int		i;
	int		tmp;
	bool	swapped;

	while (size > 0)
	{
		i = 0;
		swapped = false;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
			i++;
		}
		if (!swapped)
			break ;
		size--;
	}
}

static int	get_index(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack *a)
{
	int		*arr;
	t_stack	*tmp;
	int		size;

	size = stack_len(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	fill_arr(a, arr);
	bubble_sort(arr, size);
	tmp = a;
	while (tmp)
	{
		tmp->index = get_index(arr, size, tmp->data);
		tmp = tmp->next;
	}
	free(arr);
}
