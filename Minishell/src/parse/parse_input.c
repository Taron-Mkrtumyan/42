/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:55:04 by gkankia           #+#    #+#             */
/*   Updated: 2025/09/29 15:39:36 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_operator(t_minishell *sh, int *i)
{
	char	*op;

	if (sh->line[*i] == '<' && sh->line[*i + 1] == '<')
	{
		op = ft_strdup("<<");
		*i += 2;
	}
	else if (sh->line[*i] == '>' && sh->line[*i + 1] == '>')
	{
		op = ft_strdup(">>");
		*i += 2;
	}
	else
	{
		op = malloc(2);
		if (!op)
			return (NULL);
		op[0] = sh->line[*i];
		op[1] = '\0';
		(*i)++;
	}
	return (op);
}

char	*collect_argument(t_minishell *sh, int *i)
{
	char	*arg;
	char	*piece;

	arg = NULL;
	while (sh->line[*i])
	{
		if (is_special(sh->line[*i]))
			break ;
		if (is_quote(sh->line[*i]))
			piece = copy_quoted_arg(sh, i);
		else
			piece = copy_unquoted_arg(sh, i);
		if (!piece)
			return (free(arg), NULL);
		arg = str_join_free(arg, piece);
	}
	return (arg);
}

int	append_arg(char **args, int *k, t_minishell *sh, int *i)
{
	char	*arg;

	if (sh->line[*i] == '<' || sh->line[*i] == '>' || sh->line[*i] == '|')
		arg = get_operator(sh, i);
	else
		arg = collect_argument(sh, i);
	if (!arg)
		return (0);
	if (arg[0] == '\0')
	{
		free(arg);
		return (1);
	}
	args[*k] = arg;
	(*k)++;
	return (1);
}

int	check_redirection(t_minishell *sh, char **args, int k)
{
	if (k == 0)
		return (0);
	if (is_redirection(args[k - 1]))
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		sh->exit_code = 2;
		free_all(args, k);
		return (1);
	}
	return (0);
}

char	**parse_input(t_minishell *sh)
{
	char	**args;
	int		i;
	int		k;

	args = ft_calloc(sizeof(char *), 1024);
	i = 0;
	k = 0;
	while (sh->line[i])
	{
		i = skip_spaces(sh->line, i);
		if (!sh->line[i])
			break ;
		if (!append_arg(args, &k, sh, &i) || k >= 1023)
		{
			if (k >= 1023)
				printf("minishell: too many arguments\n");
			free_all(args, k);
			return (NULL);
		}
	}
	if (check_redirection(sh, args, k))
		return (NULL);
	args[k] = NULL;
	return (args);
}
