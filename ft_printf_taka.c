#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				//ft_putchar_fdで後ろの変数を標準出力に書く va_arg(args, int);
			}
			else if (*format == 'd')
			{
				//ft_putnbr_fdで後ろの変数を標準出力に書く va_arg(args, int);
			}
			else if (*format == 's')
			{
				//ft_putst5r_fdで後ろの変数を標準出力に書く va_arg(args, *char)
			}
			//ほかのフォーマットの処理も書く
			else
			{
				//フォーマット指定子がわからない場合はエラーを返す（エラーメッセージを書くのかは不明）
			}
		}
		else
		{
			//ft_putchar_fdでformatを書く
		}
	}
	va_end(args); // すべての処理が終わったので引数のリストを閉じる
	return (0)
}
