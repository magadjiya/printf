#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <unistd.h>
#include <stdarg.h>

/* Global Variables */

/* Function Declarations */
int _printf(const char *format, ...);
int char_specifiers(const char *format, va_list args);
int int_specifiers(const char *format, va_list args);
int _strlen(char *s);
int _putchar(char c);
int isValid_specifier(char c);

#endif /* MAIN_H */
