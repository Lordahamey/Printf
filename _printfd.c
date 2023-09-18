#include "main.h"

/**
 * _printfd - Print integers to stdout.
 * @print_me: Will print from this list.
 *
 * Return: Nothing.
 */

int _printfd(va_list print_me)
{
	int integer = 0, calc_l = 0;
	char integer_s[24];

	integer = va_arg(print_me, int);
	calc_l = snprintf(integer_s, sizeof(integer_s), "%d", integer);
	if ((calc_l < 0) || (calc_l >= (int)sizeof(integer_s)))
	{
		return (-1);
	}
	write(1, integer_s, calc_l);
	return (calc_l);
}
