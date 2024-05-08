/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:36:35 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 20:55:14 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next(char ch, va_list ap)
{
	int	length;

	length = 0;
	if (ch == 'c')
		length += check_c(ap);
	else if (ch == 's')
		length += check_s(ap);
	else if (ch == 'p')
		length += check_p(ap);
	else if (ch == 'd' || ch == 'i')
		length += check_i_d(ap);
	else if (ch == 'u')
		length += check_u(ap);
	else if (ch == 'x')
		length += check_x(ap);
	else if (ch == 'X')
		length += check_up_x(ap);
	else if (ch == '%')
		length += ft_putchar(ch);
	return (length);
}

int	ft_printf(const char *inner_arg, ...)
{
	va_list	ap;
	char	ch;
	int		ret_value;

	ret_value = 0;
	va_start(ap, inner_arg);
	while (*inner_arg)
	{
		ch = *inner_arg++;
		if (ch == '%')
		{
			ch = *inner_arg++;
			ret_value += check_next(ch, ap);
		}
		else
		{
			ft_putchar(ch);
			ret_value++;
		}
	}
	va_end(ap);
	return (ret_value);
}
