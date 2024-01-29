#include "main.h"

/**
 * _printf - my own manual printf function !
 * @format: formatted string
 * Return: length of formatted string w/o '\0'
 */
int _printf(const char *format, ...)
{
	int length = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			length++;
		}
		else
		{
			format++;
			length += char_specifiers(format, args);
		}
		format++;
	}
	va_end(args);
	return (length);
}
