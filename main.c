#include <stdio.h>

int main(void)
{
	// int a = ft_printf("%s %i%c", "hello", 5, 'a');
	// printf("Return value:  %d\n", a);

	// printf("\n------------↑mine:   ↓original------------\n\n");

	// a = ft_printf("%s %i%c", "hello", 5, 'a');
	// printf("Return value: %d\n", a);
	unsigned int a=-1;
	char	*str = ft_unsitoa(a);
	printf("%s", str);
	ft_printf("%s", str);
}