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
		case 'i':
		case 'd':
		{
			integer = va_arg(args, int);
			intToStr = num_to_str(integer);
			length += write(1, intToStr, _strlen(intToStr));
			break;
		}
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
	int count = 0, digit, first, last, len_i, size, isNegative = 0;
	char temp;
	char *str;

	len_i = i < 0 ? -i : i;
	while (len_i != 0)
	{
		len_i /= 10;
		count++;
	}

	size = i < 0 ? count += 2 : count++; /* 2 for minus, 1 for null */
	str = malloc(size * sizeof(char));
	if (i < 0)
	{
		isNegative = 1;
		i = -i;
	}
	while (i != 0)
	{
		digit = i % 10;
		str[count++] = digit + '0';
		i /= 10;
	}

	if (isNegative)
		str[count++] = '-';
	str[count] = '\0';

	first = 0; /* Make the string un reversed */
	last = count - 1;
	while (first < last)
	{
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}

	return (str);
}
