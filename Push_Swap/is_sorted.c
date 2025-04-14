/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:42:33 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/14 17:42:37 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_sorted(t_stack *a)
{
    while(a->next)
    {
        if (a->data > a->next->data)
            return (false);
        a = a->next;
    }
    return (true);
}