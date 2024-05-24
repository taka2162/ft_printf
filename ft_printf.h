/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:25:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/05/23 13:43:34 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_put_pointer(void *p);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putnbr_unsign(unsigned int n);
ssize_t	ft_put_hexa(unsigned long long x);
ssize_t	ft_put_upper_hexa(unsigned long long x);

#endif