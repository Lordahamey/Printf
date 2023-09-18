#include "main.h"

/**
 * _printfc - Print character specified by %c format.
 * @print_me: List of what to print.
 *
 * Return: Nothing.
 */

int _printfc(va_list print_me)
{
	int c = 0;

	c = va_arg(print_me, int);

	write(1, &c, 1);
	return (1);
}
