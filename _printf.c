#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int buff_ind = 0;
	int ch = va_arg(args, int);
	char *str = va_arg(args, char*);
	char buffer[BUFF_SIZE];

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					count += buff_ind;
				}
			}
			else if (*format == 'c')
			{
				buffer[buff_ind++] = ch;
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					count += buff_ind;
				}
			}
			else if (*format == 's')
			{
				while (*str)
				{
					buffer[buff_ind++] = *str;
					str++;
					if (buff_ind == BUFF_SIZE)
					{
						print_buffer(buffer, &buff_ind);
						count += buff_ind;
					}
					
				}
			}
			else
			{
				buffer[buff_ind++] = *format;
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					count += buff_ind;
				}
			}
			format++;
		}
		print_buffer(buffer, &buff_ind);
		count += buff_ind;

		va_end(args);
	}
	return (count);
}
int print_integer(int value)
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
