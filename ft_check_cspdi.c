/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cspdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:57:56 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 17:02:15 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t	check_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (ft_putchar(c));
}

ssize_t	check_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	return (ft_putstr(s));
}

ssize_t	check_p(va_list ap)
{
	void	*p;
	char	*p_ptr;
	ssize_t	len;

	len = 0;
	p = va_arg(ap, void *);
	if (p == NULL)
	{
		len = ft_putstr("0x0");
		return (len);
	}
	else
	{
		p_ptr = ft_itoa_base((unsigned long long)p);
		len += ft_putstr("0x");
		len += ft_putstr(p_ptr);
		free(p_ptr);
	}
	return (len);
}

ssize_t	check_i_d(va_list ap)
{
	int		d;
	ssize_t	len;
	char	*d_str;

	len = 0;
	d = va_arg(ap, int);
	d_str = ft_itoa(d);
	len += ft_putstr(d_str);
	free(d_str);
	return (len);
}
