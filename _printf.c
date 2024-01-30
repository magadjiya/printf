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

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
			length += write(1, format, 1);
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			if (isValid_specifier(*format))
				length += char_specifiers(format, args);
		}
		format++;
	}
	va_end(args);
	return (length);
}
