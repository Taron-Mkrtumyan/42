/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:46:31 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/27 20:07:21 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	my_sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sorty3(a);
	else if (stack_len(*a) == 4)
		sorty4(a, &b);
	/*else
		merge_sort(a, &b);*/
}
