/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:48:49 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/13 20:13:41 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*add_node(t_stack *last, char *num, int i)
{
	t_stack node;

	node = malloc (sizeof(t_stack));
	node.next =
}

void	*a_init(t_stack *a, char **av)
{
	t_stack	*last;
	int	i;

	i = 0;
	a = malloc (sizeof(t_stack));
	if (!a)
		return (NULL);
	a.data = ft_atoi(*av);
	a.index = i++;
	last = a;
	while (++av[i])
	{
		last = add_node(last, *av, i);
		i++;
	}
	return (a);
}
