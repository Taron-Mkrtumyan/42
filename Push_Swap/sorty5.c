/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorty5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:57:35 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/30 16:00:25 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorty5(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	if ((*a)->next->next->next->next->data == min)
		rra(a);
	else if ((*a)->next->next->next->data == min)
	{
		rra(a);
		rra(a);
	}
	while ((*a)->data != min)
		ra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sorty4(a, b);
	pa(a, b);
}
