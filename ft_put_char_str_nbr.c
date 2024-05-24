/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_str_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:24:42 by ttakino           #+#    #+#             */
/*   Updated: 2024/05/23 12:24:42 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", ft_strlen("(null)"));
		return (ft_strlen("(null)"));
	}
	return (write(1, str, ft_strlen(str)));
}

ssize_t	ft_putnbr(int n)
{
	ssize_t	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		count++;
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count++;
	ft_putchar(n % 10 + '0');
	return (count);
}

ssize_t	ft_putnbr_unsign(unsigned int n)
{
	ssize_t	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count++;
	ft_putchar(n % 10 + '0');
	return (count);
}
