#ifndef MAIN_H
#define MAIN_H

/* Header Files */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/* Global Variables */

/* Function Declarations */
int _printf(const char *format, ...);
int char_specifiers(const char *format, va_list args);
int int_specifiers(const char *format, va_list args);
int _putchar(char c);
int _strlen(char *s);
int isValid_specifier(char c);
char *num_to_str(int i);

#endif /* MAIN_H */
