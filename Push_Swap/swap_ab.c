/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:46:32 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/27 18:30:15 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_first_two(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->prev = NULL;
	(*a)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*a);
	tmp->next = (*a);
	(*a) = tmp;
}

void	sa(t_stack **a)
{
	swap_first_two(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_first_two(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_first_two(a);
	swap_first_two(b);
	write(1, "ss\n", 3);
}
