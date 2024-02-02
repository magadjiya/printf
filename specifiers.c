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
			if (str == NULL)
				str = "(null)";
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


#include "main.h"

/**
 * int_specifiers - checks and handles digit specifiers
 * @format: the format string
 * @args: the argument list
 * Return: total length
 */
int int_specifiers(const char *format, va_list args)
{
	int length = 0, integer;
	char *intToStr;

	switch (*format)
	{
		case 'i' || 'd':
		{
			integer = va_arg(args, int);
			intToStr = num_to_str(integer);
			length += write(1, intToStr, _strlen(intToStr));
			break;
		}
		default:
			length += write(1, format, 1);
	}
	va_end(args);
	return (length);
}

#include "main.h"

/**
 * num_to_str - converts a number to a string
 * @i: the number
 * Return: the new string
 */
char *num_to_str(int i)
{
	int length;
	char *str;

	length = snprintf(NULL, 0, "%d", i);
	str = malloc(length + 1);
	snprintf(str, length + 1, "%d", i);

	return (str);
}
