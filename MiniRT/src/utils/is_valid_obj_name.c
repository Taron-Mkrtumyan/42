/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:47 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/02/27 17:52:29 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_valid_obj_name(char *line)
{
	if (line[0] && line[0] >= 'A' && line[0] <= 'Z')
	{
		if (line[1] && ft_isspace(line[1]))
			return (true);
		else
			return (false);
	}
	else if (line[0] && line[0] >= 'a' && line[0] <= 'z')
	{
		if (line[1] && line[1] >= 'a' && line[1] <= 'z')
		{
			if (line[2] && ft_isspace(line[2]))
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
	return (true);
}
