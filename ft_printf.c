/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:36:35 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 15:47:54 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_printf(const char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s, *d_str, *p_ptr;
	void *p;
	unsigned int  x, X;

	char ch;

	d_str = NULL;
	int ret_value = 0;

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
				if (p == NULL)
					ret_value += ft_putstr("0x0");
				else
				{
					p_ptr = ft_itoa_base((unsigned long long)p);
					ret_value += ft_putstr("0x");
					ret_value += ft_putstr(p_ptr);
					free(p_ptr);
				}
			}
			else if (ch == 'd' || ch == 'i') /* int */
			{
				d = va_arg(ap, int);
				d_str = ft_itoa(d);
				ret_value += ft_putstr(d_str);
				free(d_str);
			}
			else if (ch == 'u')
			{
				char *u_str = NULL;
				unsigned int u = va_arg(ap, unsigned int);
				u_str = ft_unsitoa(u);
				ret_value += ft_putstr(u_str);
				free(u_str);
			}
			else if (ch == 'x')
			{
				x = va_arg(ap, unsigned int);
				if (x == 0)
					ret_value += ft_putstr("0");
				char *x_ptr = ft_itoa_base(x);
				ret_value += ft_putstr(x_ptr);
				free(x_ptr);
			}
			else if (ch == 'X')
			{
				X = va_arg(ap, unsigned int);
				if (X == 0)
					ret_value += ft_putstr("0");
				char *X_ptr = ft_itoa_upbase(X);
				ret_value += ft_putstr(X_ptr);
				free(X_ptr);
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
	va_end(ap2);
	return (ret_value);
}
