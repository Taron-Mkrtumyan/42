/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:02:10 by tmkrtumy          #+#    #+#             */
/*   Updated: 2026/03/06 19:02:49 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	parse_error(char *msg, char **params, int file_line)
{
	if (msg)
		error_msg(msg);
	printf(BRIGHT_CYAN"(line: %d)\n"RESET, file_line);
	if (params)
		free_arr(params);
	return (false);
}

bool	parse_error_ptr(char *msg, void *ptr, char **params, int file_line)
{
	error_msg(msg);
	printf(BRIGHT_CYAN"(line: %d)\n"RESET, file_line);
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	if (params)
		free_arr(params);
	return (false);
}

bool	error_msg(char *msg)
{
	ft_putstr_fd(BRED"Error\n"RESET, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (false);
}
