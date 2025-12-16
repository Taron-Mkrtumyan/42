/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:22:25 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/09/17 17:23:52 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_flag_n(char *arg)
{
	int	i;

	if (!arg || arg[0] != '-')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	builtin_echo(t_minishell *sh)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	while (sh->args[i] && is_flag_n(sh->args[i]))
	{
		newline = 0;
		i++;
	}
	while (sh->args[i])
	{
		ft_putstr_fd(sh->args[i], sh->out_fd);
		i++;
		if (sh->args[i])
			ft_putchar_fd(' ', sh->out_fd);
	}
	if (newline)
		ft_putchar_fd('\n', sh->out_fd);
	sh->exit_code = 0;
	return (1);
}
