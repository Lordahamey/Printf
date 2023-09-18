#include "main.h"

/**
 * b_binary - Handle and convert to binary.
 * @print_me: The list.
 *
 * Return: Nothing.
 */

char *b_binary(va_list print_me)
{
	unsigned int nb = 0;
	char *b;
	int idx = 0, n_bit = 0, bit_s = -1;
	int b_size = 0;

	nb = va_arg(print_me, unsigned int);

	for (n_bit = 31; n_bit >= 0; n_bit--)
	{
		if ((nb >> n_bit) & 1)
		{
			bit_s = n_bit;
			break;
		}
	}
	b_size = (bit_s == -1) ? 1 : (bit_s + 1);
	b = (char *)malloc(b_size + 1);

	if (b == NULL)
	{
		return (NULL);
	}

	for (idx = 0; idx < b_size; idx++)
	{
		b[idx] = ((nb >> (b_size - idx - 1)) & 1) ? '1' : '0';
	}

	b[b_size] = '\0';
	write(1, b, b_size);

	return (b);
}
