#include "main.h"
#include <string.h>
#include <stdlib.h>
/**
 * get_flags - calculate active flags
 * @format: string format in which to print the arguments
 * @i: parameter input
 * Return: upon success flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int y, curr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[curr] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = curr - 1;

	return (flags);
}
