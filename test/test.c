/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:36:35 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 15:40:47 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char *fmt, ...)
{
	va_list ap, ap2;
	int d, i;
	unsigned int u, x, X;
	char c, *s;
	void *p;

	char ch;
	int		ret_value = 0;

	va_start(ap, fmt);
	va_copy(ap2, ap);
	while (*fmt)
	{
		ch = *fmt++;
		if (ch == '%')
		{
			ch = *fmt++;
			if (ch == 'c') /* char */
			{
				c = va_arg(ap, int);
				ret_value += ft_putchar(c);
			}
			else if (ch == 's') /* string */
			{
				s = va_arg(ap, char *);
				ret_value += ft_putstr(s);
			}
			else if (ch == 'p')
			{
				p = va_arg(ap, void *);
				ret_value += ft_putstr(p);
			}
			else if (ch == 'd') /* int */
			{
				d = va_arg(ap, int);
				// printf("putnbr: %zd\n", ft_putnbr(d));
				ret_value += ft_putnbr(d);
			}
			else if (ch == 'i')
			{
				i = va_arg(ap, int);
				ret_value += ft_putnbr(i);
			}
			else if (ch == 'u')
			{
				u = va_arg(ap, int);
				ret_value += ft_putnbr(u);
			}
			else if (ch == 'x')
			{
				x = va_arg(ap, unsigned int);
				ret_value += ft_putnbr(x);
			}
			else if (ch == 'X')
			{
				X = va_arg(ap, unsigned int);
				ret_value += ft_putnbr(X);
			}
			else if (ch == '%')
			{
				ret_value += ft_putchar(ch);
			}
		}
		else
		{
			ft_putchar(ch);
			ret_value++;
		}
	}
	va_end(ap);
	//    ...
	//    /* use ap2 to iterate over the arguments again */
	//    ...
	va_end(ap2);
	return (ret_value);
}
