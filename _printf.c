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
	char c;

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
			if (*format == '\0')
				break;
			switch (*format)
			{
				case 'c':
				{
					c = va_arg(args, int);
					write(1, &c, 1);
					length++;
					break;
				}
				case '%':
				{
					write(1, "%", 1);
					length++;
					break;
				}
				default:
					other_specifiers(format);
			}
		}
		format++;
	}
	va_end(args);
	return (length);
}
