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
	int k, printed = 0, printed_chars = 0;
	int precision, width, size, flags, buff_ind = 0;
	va_list args;

	char buffer[BUFF_SIZE];

	va_start(args, format);
	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')/*check for the start of a conversion specifier*/
		{
			buffer[buff_ind++] = format[k];

			if (buff_ind == BUFF_SIZE)
				/*flash the buffer and print its content*/
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &k);
			width = get_width(format, &k, args);
			precision = get_precision(format, &k, args);
			size = get_size(format, &k);
			++k;
			printed = handle_print(format, &k, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;
	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - print chars in the buffer
 * @buffer: Array of chars
 * @index: inex of characters
 */
void print_buffer(char *buffer, int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
