#include "main.h"
#include <string.h>
#include <stdlib.h>
/* print pointer */
/**
 * print_pointer - prints pointer variable
 * @types: arguments parameters
 * @buffer: array buffer
 * @flags:  calculates active flags
 * @width: gets the width
 * @precision: precision specification
 * @size: specifier size
 * Return: pointer to the characters.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;
	index++;
	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_c, padd_start));
}
/* non printable*/
/**
 * print_non_printable - prints ascii codes in hexa of non printable characters
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = 0, set = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[y] != '\0')
	{
		if (printable(str[y]))
			buffer[y + set] = str[y];
		else
			set += append_hexa_code(str[y], buffer, y + set);

		y++;
	}

	buffer[y + set] = '\0';

	return (write(1, buffer, y + set));
}
/*reverse function*/
/**
 * print_reverse - prints string in reverse
 * @types: arguments list
 * @buffer: array buffer
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: reversed string
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int y, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (y = 0; str[y]; y++)
		;

	for (y = y - 1; y >= 0; y--)
	{
		char f = str[y];

		write(1, &f, 1);
		counter++;
	}
	return (counter);
}
/*string in rot13 */
/**
 * print_rot13string - print a string in rot13.
 * @types: Lista of arguments
 * @types: arguments list
 * @buffer: array buffer
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: rot13 of a string
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char m;
	char *str;
	unsigned int i, j;
	int counter = 0;
	char k[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char a[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; k[j]; j++)
		{
			if (k[j] == str[i])
			{
				m = a[j];
				write(1, &m, 1);
				counter++;
				break;
			}
		}
		if (!k[j])
		{
			m = str[i];
			write(1, &m, 1);
			counter++;
		}
	}
	return (counter);
}
