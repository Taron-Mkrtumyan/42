/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:27:22 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/15 18:09:06 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sign);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 19 || \
(ft_strlen(str) == 19 && ft_strcmp(str, "9223372036854775807") > 0))
		return (0);
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(t_minishell *sh)
{
	long long	code;

	write(1, "exit\n", 5);
	if (!sh->args[1])
	{
		free_minishell(sh);
		exit(sh->exit_code);
	}
	if (!is_numeric(sh->args[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(sh->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_minishell(sh);
		exit(2);
	}
	if (sh->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		sh->exit_code = 1;
		return (1);
	}
	code = ft_atoll(sh->args[1]);
	free_minishell(sh);
	exit((unsigned char)code);
}
