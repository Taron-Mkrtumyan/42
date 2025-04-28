/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:47:05 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/28 14:49:42 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *s)
{
	int	min;

	min = s->data;
	s = s->next;
	while (s)
	{
		if (s->data < min)
			min = s->data;
		s = s->next;
	}
	return (min);
}

void	sorty4(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->data != min)
		ra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sorty3(a);
	pa(a, b);
}
