/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:54:14 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/11/05 20:00:55 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	special_cases(int nb)
{
	if (nb == 0)
		write (1, "0", 1);
	else
		write (1, "-2147483648", 11);
}

void	ft_putnbr(int nb)
{
	int		k;
	char	num[20];
	int		i;

	if (nb == -2147483648 || nb == 0)
	{
		special_cases(nb);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		k = nb % 10;
		num[i] = k + '0';
		i++;
		nb /= 10;
	}
	while (--i >= 0)
		write(1, &num[i], 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
/*
int	main(void)
{
	int		ac;
	char	*av[4];

	av[1] = "Ta ron";
	av[3] = "absde";
	av[0] = "another string";
	av[2] = "asdsafd";
	ac = 4;
	ft_show_tab(ft_strs_to_tab(ac, av));
	return (0);
}*/
