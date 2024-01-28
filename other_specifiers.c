#include "main.h"

/**
 * other_specifiers - check other format specifiers
 * @format: strings, ints
 * Return: total length of string
 */
int other_specifiers(const char *format, ...)
{
	int length = 0;
	char c;
	va_list args;

	va_start(args, format);

	switch (*format)
	{
		case 'c':
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			length++;
			break;
		}
	}
	va_end(args);
	return (length);
}
