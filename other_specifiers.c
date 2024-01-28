#include "main.h"

/**
 * other_specifiers - check other format specifiers
 * @format: strings, ints
 * Return: total length of string
 */
int other_specifiers(const char *format, ...)
{
	int length = 0/*, i*/;
	char *str;
	va_list args;

	va_start(args, format);

	switch (*format)
	{
		case 's':
		{
			str = va_arg(args, char *);
			if (*str == '\0')
				break;
			write (1, str, _strlen(str));
			length += _strlen(str);
			break;
		}
	}
	va_end(args);
	return (length);
}
