/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_uxx_per.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:45:56 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 19:20:49 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	check_u(va_list ap)
{
	char			*u_str;
	unsigned int	u;
	ssize_t			len;

	len = 0;
	u = va_arg(ap, unsigned int);
	u_str = ft_unsitoa(u);
	len += ft_putstr(u_str);
	free(u_str);
	return (len);
}

ssize_t	check_x(va_list ap)
{
	unsigned int	x;
	char			*x_str;
	ssize_t			len;

	len = 0;
	x = va_arg(ap, unsigned int);
	if (x == 0)
		len += ft_putstr("0");
	x_str = ft_itoa_base(x);
	len += ft_putstr(x_str);
	free(x_str);
	return (len);
}

ssize_t	check_up_x(va_list ap)
{
	unsigned int	x_up;
	char			*x_up_str;
	ssize_t			len;

	len = 0;
	x_up = va_arg(ap, unsigned int);
	if (x_up == 0)
		len += ft_putstr("0");
	x_up_str = ft_itoa_upbase(x_up);
	len += ft_putstr(x_up_str);
	free(x_up_str);
	return (len);
}
