/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:44:45 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/05 18:04:38 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*nc;

	new_lst = NULL;
	while (lst)
	{
		nc = f(lst -> content);
		if (!nc)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		node = ft_lstnew(nc);
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			free(nc);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
