/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:07:12 by cimy              #+#    #+#             */
/*   Updated: 2024/05/07 19:22:56 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa_base(unsigned long long value);
char	*ft_itoa_upbase(unsigned long long value);
char	*ft_unsitoa(unsigned int n);
ssize_t	ft_putchar(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *fmt, ...);
int		check_next(char ch, va_list ap);
ssize_t	check_c(va_list ap);
ssize_t	check_s(va_list ap);
ssize_t	check_p(va_list ap);
ssize_t	check_i_d(va_list ap);
ssize_t	check_u(va_list ap);
ssize_t	check_x(va_list ap);
ssize_t	check_up_x(va_list ap);

#endif