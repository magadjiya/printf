#include "main.h"

/**
 * _printf - my own manual printf function !
 * @format: formatted string
 * Return: length of formatted string w/o '\0'
 */
int _printf(const char *format, ...)
{
	int length = 0;
	char c;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case '%':
				{
					write(1, "%", 1);
					length++;
					break;
				}
				case 'c':
				{
					c = va_arg(args, int);
					write(1, &c, 1);
					length++;
					break;
				}
				default:
					other_specifiers(format);
			}
		}
		else
			write(1, format, 1);
		format++;
		length++;
	}
	return (length);
}
