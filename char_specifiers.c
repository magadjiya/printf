#include "main.h"

/**
 * char_specifiers - check other format specifiers
 * @format: strings, ints
 * @args: the argument list;
 * Return: total length of string
 */
int char_specifiers(const char *format, va_list args)
{
	int length = 0;
	char c;
	char *str;

	switch (*format)
	{
		case 'c':
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			length++;
			break;
		}
		case 's':
		{
			str = va_arg(args, char *);
			write(1, str, _strlen(str));
			length += _strlen(str);
			break;
		}
		case '%':
		{
			write(1, format, 1);
			length++;
			break;
		}
		default:
			length += int_specifiers(format, args);
	}
	va_end(args);
	return (length);
}
