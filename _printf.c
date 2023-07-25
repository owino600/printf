#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int ch = va_arg(args, int);
	char *str = va_arg(args, char*);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				putchar(ch);
				count++;
			}
			else if (*format == 's')
			{
				while (*str)
				{
					putchar(*str);
					str++;
					count++;
				}
			}
			else
			{
				putchar(*format);
				count++;
			}
			format++;
		}
		va_end(args);
	}
	return (count);
}
int rint_int(int value)
{
	int i;
	char buffer[32];
	int printed = snprintf(buffer, sizeof(buffer), "%d", value);

	for (i = 0; i < printed; i++)
	{
		putchar(buffer[i]);
	}
	return (printed);
}
void print_buffer(char buffer[], int *buff_ind)
{
	int i;

	if (*buff_ind > 0)
	{
		for (i = 0; i < *buff_ind; i++)
		{
			putchar(buffer[i]);
		}
	}
	*buff_ind = 0;
}
