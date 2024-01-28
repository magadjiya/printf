#include <unistd.h>

/**
 * _putchar - prints character to stdout
 * @c: the character
 * Return: number of bytes, -1 on fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
