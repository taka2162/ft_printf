/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:07:12 by cimy              #+#    #+#             */
/*   Updated: 2024/05/06 14:07:45 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void 	foo(char *fmt, ...);
ssize_t	ft_putchar(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int 	ft_printf(const char *fmt, ...);

#endif