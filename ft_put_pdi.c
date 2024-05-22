#include "ft_printf.h"

ssize_t	ft_print_id(va_list arg)
{
	int		num;
	ssize_t	len;
	char	*nbr;
	
	num = va_arg(arg, int);
	len = 0;
	nbr = ft_itoa(num);
	len += ft_putstr(nbr);
	free(nbr);
	return (len);
}