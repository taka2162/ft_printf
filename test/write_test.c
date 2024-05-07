#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


static int	digit_count(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n > 0)
	{
		while (n > 0)
		{
			n = n / 10;
			count++;
		}
	}
	else
	{
		while (n < 0)
		{
			n = n / 10;
			count++;
		}
	}
	return (count);
}

static char	*malloc_memory(int n, int digit)
{
	char	*result;

	result = NULL;
	if (n < 0)
	{
		result = (char *)malloc(sizeof(char) * (digit + 2));
		if (result != NULL)
		{
			result[0] = '-';
			result[digit + 1] = '\0';
		}
	}
	else if (n >= 0)
	{
		result = (char *)malloc(sizeof(char) * (digit + 1));
		if (result != NULL)
			result[digit] = '\0';
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*result;

	digit = digit_count(n);
	result = malloc_memory(n, digit);
	if (result == NULL)
		return (NULL);
	while (digit > 0)
	{
		if (n >= 0)
			result[--digit] = (n % 10) + '0';
		else
			result[--digit + 1] = -(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}


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

static int	ft_int_strlen(unsigned long long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_strrev(char *str)
{
	char	tmp;
	int	i;
	int	j;

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
	len = ft_int_strlen(value);
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



int main(void)
{
	// int n = 10;
	// char *str = ft_itoa(n);
	char	*str = NULL;
	char *result = ft_itoa_base((unsigned long long)str);
	// ft_putstr((void *)result);
	printf("Address of str is: %d\n", (unsigned long long)str);
	
	// printf("%s", NULL);

	
}

//OUTPUT
//abcdefabcdefabcdefabcdefabcdefabcdef123456