#include "main.h"
/*unsigned number function*/
/**
 * print_unsigned - prints an unsigned number
 * @types: arguments list
 * @buffer: array buffer to print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of character
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int no = va_arg(types, unsigned long int);

	no = convert_size_unsgnd(no, size);

	if (no == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (no > 0)
	{
		buffer[y--] = (no % 10) + '0';
		no /= 10;
	}

	y++;

	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}

/*function to print unsigned oct */
/**
 * print_octal - prints an unsigned number in octal
 * @types: arguments list
 * @buffer: array buffer to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of character
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int y = BUFF_SIZE - 2;
	unsigned long int d = va_arg(types, unsigned long int);
	unsigned long int init_no = d;

	UNUSED(width);

	d = convert_size_unsgnd(d, size);

	if (d == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (d > 0)
	{
		buffer[y--] = (d % 8) + '0';
		d /= 8;
	}

	if (flags & F_HASH && init_no != 0)
		buffer[y--] = '0';

	y++;

	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}

/*hexadecimal functio*/
/**
 * print_hexadecimal - prints unsigned number in hexadecimal
 * @types: argument list
 * @buffer: array buffer to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: pPrecision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/*upper hex function*/
/**
 * print_hexa_upper - prints an unsigned number in upper hexadecimal
 * @types: argumen lits
 * @buffer: array buffer to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of characters
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*upper or lower function*/
/**
 * print_hexa - Ppints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: array of values to map the number to
 * @buffer: array buffer  to handle print
 * @flags: calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: number of characters
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int y = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_no = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[y--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[y--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_no != 0)
	{
		buffer[y--] = flag_ch;
		buffer[y--] = '0';
	}

	y++;

	return (write_unsgnd(0, y, buffer, flags, width, precision, size));
}
