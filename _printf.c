#include "main.h"

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
	int format_c = 0, c_idx = 0;
	char *b_str = 0;
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
			else
			{
				if (format[format_c] == 'c')
				{
					c_idx = c_idx + _printfc(print_me);
				}
				else if (format[format_c] == 's')
				{
					c_idx = c_idx + _printfs(print_me);
				}
				else if (format[format_c] == 'd' || format[format_c] == 'i')
				{
					c_idx = c_idx + _printfd(print_me);
				}
				else if (format[format_c] == 'b')
				{
					b_str = b_binary(print_me);
					if (b_str != NULL)
					{
						c_idx += strlen(b_str);
						free(b_str);
					}
				}
				format_c++;
			}
		}
	}
	va_end(print_me);
	return (c_idx);
}
