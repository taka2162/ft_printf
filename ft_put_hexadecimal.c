#include "ft_printf.h"

ssize_t	ft_put_pointer(void *p)
{
	ssize_t	len;

	len = 0;
	if (p == NULL)
	{
		len += ft_putstr("0x0");
		return (len);
	}
	else
	{
		len += ft_putstr("0x");
		len += ft_put_hexa((unsigned long long)p);
		return (len);
	}
}

ssize_t	ft_put_hexa(unsigned long long x)
{
	ssize_t	count;

	count = 0;
	if (x >= 16)
		count += ft_put_hexa(x / 16);
	count++;
	ft_putchar("0123456789abcdef"[x % 16]);
	return (count);
}

ssize_t	ft_put_upper_hexa(unsigned long long x)
{
	ssize_t	count;

	count = 0;
	if (x >= 16)
		count += ft_put_upper_hexa(x / 16);
	count++;
	ft_putchar("0123456789ABCDEF"[x % 16]);
	return (count);
}