/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:45:48 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 15:48:37 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", ft_strlen("(null)"));
		return (ft_strlen("(null)"));
	}
	return (write(1, &*s, ft_strlen(s)));
}

ssize_t	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	count++;
	ft_putchar(n % 10 + '0');
	return (count);
}
