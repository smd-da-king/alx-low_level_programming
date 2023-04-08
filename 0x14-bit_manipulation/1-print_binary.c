#include "main.h"

/**
 * print_binary - Entry point
 * Description: Prints the binary representation of a number
 * @n: Printed in binary format
 */

void print_binary(unsigned long int n)
{
	int j = 0;

	/* Locate position of the leftmost 1 in the binary string */
	while ((n >> j) > 1)
	{
		j++;
	}
	/* Prints the binary representation of the number */
	while (j >= 0)
	{
		if ((n >> j) & 1)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
		j--;
	}
}
