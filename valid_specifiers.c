#include "main.h"

/**
 * isValid_specifier - checks for valid specifer types
 * @c: the specifier
 * Return: true if valid, false if not
 */
int isValid_specifier(char c)
{
	int i;
	const char valid_specifiers[] = {'c', 's', '%', 'd', 'i'};

	i = 0;
	while (valid_specifiers[i])
	{
		if (c == valid_specifiers[i])
			return (1);
		i++;
	}
	return (0);
}
