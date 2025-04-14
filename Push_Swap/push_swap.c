/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:03:41 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/04/14 16:33:40 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	strintcmp(char *s)
{
	if (s[0] == '-')
	{
		if (ft_strncmp(s, "-2147483648", 11) > 0)
			return (false);
	}
	else if (s[0] == '+')
	{
		if (ft_strncmp(s, "+2147483647", 11) > 0)
			return (false);
	}
	else if (ft_strncmp(s, "2147483647", 10) > 0)
		return (false);
	return (true);
}

static bool	is_ok(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > '9' || s[i] < '0')
		{
			if (i == 0 && (s[i] == '-' || s[i] == '+'))
			{
				if (!s[i + 1] || s[i + 1] > '9' || s[i + 1] < '0')
					return (false);
			}
			else
				return (false);
		}
		i++;
	}
	if (i - (s[0] == '+' || s[0] == '-') > 10)
		return (false);
	if (i - (s[0] == '+' || s[0] == '-') < 10)
		return (true);
	return (strintcmp(s));
}

static int	hash(int key)
{
	if (key < 0)
		key = -key;
	return (key % TABLE_SIZE);
}

static bool	check_args(char **av)
{
	int		table[TABLE_SIZE];
	bool	occupied[TABLE_SIZE];
	int		i;
	int		val;
	int		idx;

	i = 0;
	idx = 0;
	while (idx < TABLE_SIZE)
		occupied[idx++] = false;
	while (av[i])
	{
		if (!is_ok(av[i]))
			return (false);
		val = ft_atoi(av[i++]);
		idx = hash(val);
		while (occupied[idx] && table[idx] != val)
			idx = (idx + 1) % TABLE_SIZE;
		if (occupied[idx])
			return (false);
		table[idx] = val;
		occupied[idx] = true;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	bool	split_flag;

	a = NULL;
	b = NULL;
	split_flag = false;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		split_flag = true;
	}
	else
		av++;
	if (!check_args(av))
		ft_putendl_fd("Error", 2);
	else if (!a_init(&a, av))
		free_stack(&a);
	else if (is_sorted (a))
		printf("Is sorted\n");
	/*else if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sorty(&a);
		else
			merge_sort(&a, &b);
	}*/
	free_stack(&a);
	if (split_flag)
		free_split (av);
	return (0);
}
