/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:09:13 by tmkrtumy          #+#    #+#             */
/*   Updated: 2024/11/02 19:33:44 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	while (*argv[0])
	{
		write (1, argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
	return (0);
}