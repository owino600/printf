#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - print function
 * @format: format
 * by daniel ft hildah
 * Return: printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;	/*initilize a counter for the number of characters printed*/
	int k;
	int buff_ind = 0; /*Buffer idex*/
	int printed = 0;
	int flags, width, precision, size;
	int ch = va_arg(args, int);
	char *str = va_arg(args, char*);
	char buffer[BUFF_SIZE];

	va_start(args, format);
	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')/*check for the start of a conversion specifier*/
		{
			buffer[buff_ind++] = format[k];
			if (buff_ind == BUFF_SIZE)
			{
				/*flash the buffer and print its content*/
				print_buffer(buffer, &buff_ind);
				count += buff_ind;
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
			print_buffer(buffer,  &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, args);
			precision = get_precision(format, &k, args);
			size = get_size(format, &k);
			++k;
			printed = handle_print(format, &k, args, buffer, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			count += printed;
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
		for (j = i - 1; j >= 0; j--)
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
