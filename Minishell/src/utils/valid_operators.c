/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:58:52 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/10/03 17:05:37 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	is_pipe(char *s)
{
	return (ft_strcmp(s, "|") == 0);
}

int	print_error_pipe(t_minishell *sh, int i)
{
	printf("minishell: syntax error near unexpected token `%s'\n", \
sh->args[i]);
	sh->exit_code = 2;
	return (0);
}

int	print_error_readir(t_minishell *sh)
{
	printf("minishell: syntax error near unexpected token `newline'\n");
	sh->exit_code = 2;
	return (0);
}

char	valid_operators(t_minishell *sh)
{
	int	i;

	i = 0;
	if (is_pipe(sh->args[0]))
		return (print_error_pipe(sh, i));
	while (sh->args[i] && sh->args[i + 1])
	{
		if (is_redirection(sh->args[i]) && \
(is_redirection(sh->args[i + 1]) || is_pipe(sh->args[i + 1])))
		{
			printf("minishell: syntax error near unexpected token `%s'\n", \
sh->args[i + 1]);
			sh->exit_code = 2;
			return (0);
		}
		i++;
	}
	if (is_redirection(sh->args[i]) || is_pipe(sh->args[i]))
		return (print_error_readir(sh));
	return (1);
}
