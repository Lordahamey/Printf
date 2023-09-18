#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _printfc(va_list print_me);
int _printfs(va_list print_me);
int _printfd(va_list print_me);
char *b_binary(va_list print_me);

#endif
