/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:17:59 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/27 17:22:35 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *a)
{
	int	max;

	max = a->data;
	a = a->next;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	return (max);
}

void	sorty3(t_stack **a)
{
	int	max;

	max = find_max(*a);
	if ((*a)->data == max)
	{
		ra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if ((*a)->next->data == max)
	{
		rra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else
		sa(a);
}
