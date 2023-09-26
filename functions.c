#include "main.h"

/*print char function*/

/**
 * print_char - prints character
 * @types: arguments list
 * @buffer: array to handle print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*function to print string*/
/**
 * print_string - Prints a string
 * @types: arguments list
 * @buffer: calculates active flags
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/*function print percent sign*/
/**
 * print_percent - prints a percent sign
 * @types: arguments list
 * @buffer: array buffer to handle print
 * @flags: calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: size specifier
 * Return: number of characters printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*int function*/
/**
 * print_int - prints integer
 * @types: arguments list
 * @buffer: array buffer to handle print
 * @flags: calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int no;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	no = (unsigned long int)n;

	if (n < 0)
	{
		no = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (no > 0)
	{
		buffer[i--] = (no % 10) + '0';
		no /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/*function print binary*/
/**
 * print_binary - Prints an unsigned number
 * @types: arguments list
 * @buffer: array buffer to handle print
 * @flags: calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: numbers of characters
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int z, m, i, sum;
	unsigned int k[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	z = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	k[0] = z / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		k[i] = (z / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += k[i];
		if (sum || i == 31)
		{
			char p = '0' + k[i];

			write(1, &p, 1);
			count++;
		}
	}
	return (count);
}
