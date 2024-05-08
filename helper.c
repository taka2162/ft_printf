/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:47:30 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 19:54:31 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cal_16(unsigned long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	if (n == 0)
		len++;
	return (len);
}

static void	ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i--;
		j++;
	}
}

char	*ft_itoa_base(unsigned long long value)
{
	char	*buf;
	int		i;
	int		len;

	i = 0;
	len = cal_16(value);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (value > 0)
	{
		buf[i++] = "0123456789abcdef"[value % 16];
		value /= 16;
	}
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}

char	*ft_itoa_upbase(unsigned long long value)
{
	char	*buf;
	int		i;
	int		len;

	i = 0;
	len = cal_16(value);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	while (value > 0)
	{
		buf[i++] = "0123456789ABCDEF"[value % 16];
		value /= 16;
	}
	buf[i] = '\0';
	ft_strrev(buf);
	return (buf);
}
