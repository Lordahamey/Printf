#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produce output base on the
 * specified format.
 * @format: Character string.
 * @...: Showing it can take many argument.
 *
 * Return: The number of character
 * that is excluding the '\0' byte.
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int format_c = 0, idx, c_idx = 0;
	int c;
	char *s;
	va_list print_me;

	va_start(print_me, format);
	if (format == NULL)
	{
		return (-1);
	}
	while (format[format_c] != '\0')
	{
		if (format[format_c] != '%')
		{
			write(1, &format[format_c], 1);
			c_idx++;
			format_c++;
		}
		else
		{
			format_c++;
			if (format[format_c] == '%')
			{
				write(1, format, 1);
				c_idx++;
				format_c++;
			}
			else if (format[format_c] == 'c')
			{
				c = va_arg(print_me, int);
				write(1, &c, 1);
				c_idx++;
				format_c++;
			}
			else if (format[format_c] == 's')
			{
				s = va_arg(print_me, char *);
				for (idx = 0; s[idx] != '\0'; idx++)
				{
				}
				write(1, s, idx);
				c_idx += idx;
				format_c++;
			}
		}
	}
	va_end(print_me);
	return (c_idx);
}
/**
 * main - Check my code.
 *
 * Return: 0 Always.
 */

int main(void)
{
	_printf("%c", 'A');
	_printf("%s", "Andrew");
	_printf("%s", "Akinola");
	_printf("%%");
	return (0);
}
