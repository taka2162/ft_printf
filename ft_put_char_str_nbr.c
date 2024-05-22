#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

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