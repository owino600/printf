#include "main.h"
/**
 * functions = _printf
 * description: custom _printf function that print fommarted output
 * @s: form strings and other arguments
 * @c: number of characters pointed
 * Return: the number of characters printed:wq
 */

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; /*initilize a counter for the number of characters printed*/
	int buff_ind = 0; /*Buffer idex*/
	int printed = 0;
	int ch = va_arg(args, int);
	char *str = va_arg(args, char*);
	char buffer[BUFF_SIZE];

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')/*check for the start of a conversion specifier*/
		{
			format++;/*move to the next character after '%'*/
			if (*format == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					/*flash the buffer and print its content*/
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
			else if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(args, int);
				printed = print_integer(value);
				count += printed;
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

	return (count);
}
int print_integer(int value)
{
	int i = 0;
	int j;
	char buffer[32];
	int printed = 0;

	if (value < 0)
	{
		putchar('-');
		printed++;
		value = -value;
	}
	/*convert each digit of the integer to a character*/
	do
	{
		buffer[i++] = '0' + (value % 10);
		value /= 10;
		printed++;
	}
	while (value > 0);
		for (j = i -1; j >= 0; j--)
		{
			putchar(buffer[j]);
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
