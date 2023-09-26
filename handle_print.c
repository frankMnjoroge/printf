#include "main.h"
#include <stdlib.h>
/**
 * handle_print - argument based on its type
 * @form: formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: array buffer
 * @flags: calculates active flags
 * @width: get width.
 * @precision: precision specification
 * @size: size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *form, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, printed_chars = -1;
	frm_z form_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; form_types[i].frm != '\0'; i++)
		if (form[*ind] == form_types[i].frm)
			return (form_types[i].func(list, buffer, flags, width, precision, size));

	if (form_types[i].frm == '\0')
	{
		if (form[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (form[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (form[*ind] != ' ' && form[*ind] != '%')
				--(*ind);
			if (form[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &form[*ind], 1);
		return (len);
	}
	return (printed_chars);
}
