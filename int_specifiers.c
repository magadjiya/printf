#include "main.h"

/**
 * int_specifiers - checks and handles digit specifiers
 * @format: the format string
 * @args: the argument list
 * Return: total length
 */
int int_specifiers(const char *format, va_list args)
{
	int length = 0, integer, size;

	switch (*format)
	{
		case 'i':
		{
			size = 1;
			integer = va_arg(args, int);
			write(1, &integer, size);
			length += size;
			break;
		}
	}
	va_end(args);
	return (length);
}
