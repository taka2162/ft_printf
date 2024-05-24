/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:25:14 by ttakino           #+#    #+#             */
/*   Updated: 2024/05/23 12:25:14 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	see_next(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		len += ft_put_pointer(va_arg(arg, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_putnbr_unsign(va_arg(arg, unsigned int));
	else if (c == 'x')
		len += ft_put_hexa(va_arg(arg, unsigned int));
	else if (c == 'X')
		len += ft_put_upper_hexa(va_arg(arg, unsigned int));
	else if (c == '%')
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	char	c;
	int		len;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		c = *format++;
		if (c == '%')
		{
			c = *format++;
			len += see_next(c, arg);
		}
		else
		{
			ft_putchar(c);
			len++;
		}
	}
	va_end(arg);
	return (len);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	len;
// 	int	num;

// 	len = 0;
// 	num = 16384;
// 	ft_printf("\x1b[35mft_printf---\n");
// 	len += ft_printf("char\t\t=\t%c\n", 'c');
// 	len += ft_printf("str\t\t=\t%s\n", "str");
// 	len += ft_printf("pointer\t\t=\t%p\n", &len);
// 	len += ft_printf("number(d)\t=\t%d\n", num);
// 	len += ft_printf("number(i)\t=\t%i\n", num);
// 	len += ft_printf("number(u)\t=\t%u\n", num);
// 	len += ft_printf("hexa(low) = %x\n", 9223372036854775807LL);
// 	len += ft_printf("hexa(up)\t=\t%X\n", num);
// 	ft_printf("percent\t\t=\t%%\n", '%');
// 	printf("\x1b[mlen = %d\n", len);
// 	len = 0;
// 	printf("\x1b[36mprintf---\n");
// 	len += printf("char\t\t=\t%c\n", 'c');
// 	len += printf("str\t\t=\t%s\n", "str");
// 	len += printf("pointer\t\t=\t%p\n", &len);
// 	len += printf("number(d)\t=\t%d\n", num);
// 	len += printf("number(i)\t=\t%i\n", num);
// 	len += printf("number(u)\t=\t%u\n", num);
// 	len += printf("hexa(low) = %x\n", 9223372036854775807LL);
// 	len += printf("hexa(up)\t=\t%X\n", num);
// 	printf("\x1b[mlen = %d\n", len);
// return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }