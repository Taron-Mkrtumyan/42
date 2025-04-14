/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:48:49 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/14 16:34:22 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*add_node(t_stack *last, char **av, int i)
{
	t_stack	*node;

	if (!av[i])
		return (NULL);
	node = malloc (sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = ft_atoi(av[i]);
	node->index = i;
	node->prev = last;
	node->next = add_node(node, av, ++i);
	return (node);
}

void	*a_init(t_stack **a, char **av)
{
	*a = malloc (sizeof(t_stack));
	if (!(*a))
		return (NULL);
	(*a)->data = ft_atoi(av[0]);
	(*a)->index = 0;
	(*a)->prev = NULL;
	(*a)->next = add_node(*a, av, 1);
	if (!(*a)->next && av[1])
		return (NULL);
	return (a);
}
