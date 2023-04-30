#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: condition:If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int digits = 0;
	unsigned int x = 0;

	/* Check if b is NULL */
	if (!b)
	{
		return (0);
	}
	/* Loop: gets the length of the binary string */
	while (b[x] != '\0')
	{
		/* Checks if char is not 0 or 1 */
		if (b[x] != '0' && b[x] != '1')
		{
			return (0);
		}
		x++;
	}
	/* Get the decimal value of the binary string */
	x = 0;
	while (b[x] != '\0')
	{
		/* Left shift the digit by 1 bit or space */
		digits <<= 1;
		if (b[x] == '1')
		{
			digits += 1;
		}
		x++;
	}
	return (digits);
}
