#include "main.h"

/**
 * _printf - my own manual printf function !
 * @format: formatted string
 * Return: length of formatted string w/o '\0'
 */
int _printf(const char *format, ...)
{
	int length = 0, i;
	char *str;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
				{
					str = va_arg(args, char *);
					for (i = 0; i < _strlen(str); i++)
					{
						_putchar(str[i]);
						length++;
					}
					break;
				}
				case '%':
				{
					write(1, "%", 1);
					length++;
					break;
				}
				default:
					length += other_specifiers(format);
			}
		}
		else
			write(1, format, 1);
		format++;
		length++;
	}
	va_end(args);
	return (length);
}
