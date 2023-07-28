#include "main.h"

/**
 * get_size - calculate the size
 * @format: formatted string
 * @k: list of arguments
 *
 * Return: size
 */

int get_size(const char *format, int *k)
{
	int current_k = *k + 1;
	int size = 0;

	if (format[current_k] == 'l')
		size = S_LONG;
	else if (format[current_k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*k = current_k - 1;
	else
		*k = current_k;

	return (size);
}
