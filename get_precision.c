#include "main.h"
#include <strings.h>
/**
 * get_precision - calculates precision
 * @format: formatted arguments
 * @i: arguments list
 * @list: arguments list
  * Return: precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);

	precision = 0;

	for (curr += 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (precision);
}
