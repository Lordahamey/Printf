#include "main.h"

/**
 * _printfs - Print to the stdout base on the %s specifier.
 * @print_me: The list where to extract from.
 *
 * Return: Nothing.
 */

int _printfs(va_list print_me)
{
	int idx;
	char *s = 0;

	s = va_arg(print_me, char *);

	if (s == NULL)
	{
		write(1, "(null_s)", 8);
	}
	else
	{
		for (idx = 0; s[idx] != '\0'; idx++)
		{
		}
		write(1, s, idx);
	}
	return (idx);
}
