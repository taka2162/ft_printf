#include <stdio.h>

int main(void)
{
	int a = ft_printf("%s %i%c", "hello", 5, 'a');
	printf("Return value:  %d\n", a);

	printf("\n------------↑mine:   ↓original------------\n\n");

	a = ft_printf("%s %i%c", "hello", 5, 'a');
	printf("Return value: %d\n", a);
}