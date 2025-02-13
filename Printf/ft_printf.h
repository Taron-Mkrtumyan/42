/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:18:44 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/02/13 16:59:20 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_put_u_fd(unsigned int n, int fd);
int	ft_puthex_low_fd(unsigned long long n, int fd);
int	ft_puthex_up_fd(unsigned long long n, int fd);
int	ft_printf(const char *s, ...);
int	ft_strlen(char *s);
int	ft_putptr_fd(void *ptr, int fd);

#endif
