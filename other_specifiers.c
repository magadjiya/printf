#include "main.h"

/**
 */
int other_specifiers(const char *otherFormats, ...)
{
	int length = 0;
	char *str;
	va_list args;

	va_start(args, otherFormats);

	switch (*otherFormats)
	{
		case 's':
		{
			str = va_arg(args, char *);

			while (*str != '\0')
			{
				write(1, str, 1);
				str++;
				length++;
			}
			break;
		}
	}
	return (length);
}
