#include "main.h"
#include <stdlib.h>
/**
 * printable - check for aprintable character
 * @c: character to be checked.
 * Return: 1 if is successful 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - adds ascci in hexadecimal code
 * @buffer: character array.
 * @i: Index at which to start adding.
 * @ascii_code: ASSCI CODE.
 * Return: upon success always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - will check for a digit in characteer
 * @c: character to be checked
 * Return: 1 if charcter is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casts number to the specified size
 * @num: value to be casted.
 * @size: number indicating the type to be casted.
 *
 * Return: casted value
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: value to be casted
 * @size: number indicating the type to be casted
 *
 * Return: casted value of number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
