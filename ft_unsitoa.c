/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimura <sshimura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:56:39 by sshimura          #+#    #+#             */
/*   Updated: 2024/05/07 15:32:37 by sshimura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*malloc_memory(unsigned int n, int digit)
{
	char	*result;

	result = NULL;
	if (n == 0)
	{
		result = (char *)malloc(sizeof(char) * (digit + 1));
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	if (n > 0)
	{
		result = (char *)malloc(sizeof(char) * (digit + 1));
		if (result != NULL)
			result[digit] = '\0';
	}
	return (result);
}

char	*ft_unsitoa(unsigned int n)
{
	int		digit;
	char	*result;

	digit = digit_count(n);
	result = malloc_memory(n, digit);
	if (result == NULL)
		return (NULL);
	result[digit] = '\0';
	while (n != 0)
	{
		result[--digit] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}
