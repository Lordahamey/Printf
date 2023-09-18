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
{
	int format_c = 0, idx, c_idx = 0;
	int c = 0, integer = 0, calc_l = 0;
	char integer_s[24];
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
			else if (format[format_c] == 'd' || format[format_c] == 'i')
			{
				format++;
				integer = va_arg(print_me, int);
				calc_l = snprintf(integer_s, sizeof(integer_s), "%d", integer);
				if ((calc_l < 0) || (calc_l >= (int)sizeof(integer_s)))
				{
					return (-1);
				}
				write(1, integer_s, calc_l);
				c_idx += calc_l;
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
