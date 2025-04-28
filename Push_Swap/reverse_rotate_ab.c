/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 19:54:15 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/27 19:54:46 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_last(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

static void	reverse_rotate_stack(t_stack **s)
{
	t_stack	*last;

	if (!s || !(*s) || !(*s)->next)
		return ;
	last = find_last(*s);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*s);
	(*s)->prev = last;
	*s = last;
}

void	rra(t_stack **a)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
