#include "main.h"
#include <string.h>
/**
 * get_size - calculates the size of the argument
 * @format:  formatted string arguments
 * @i: List of arguments to be printed.
 * Return: upon success precision.
 */
int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int size = 0;

	if (format[curr] == 'l')
		size = S_LONG;
	else if (format[curr] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr - 1;
	else
		*i = curr;

	return (size);
}
